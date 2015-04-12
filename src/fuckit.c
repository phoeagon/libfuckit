#include "fuckit.h"
#include <dlfcn.h>
#include <setjmp.h>

#if __x86_64__
  #define EIP REG_RIP
  #define ESP REG_RSP
  #define EBP REG_RBP
#else
  #define EIP REG_EIP
  #define ESP REG_ESP
  #define EBP REG_EBP
#endif

struct fuckcpp_t {
    void* _default_entry;
    ud_t * ud_obj;
    sig_atomic_t flag;
    //void ** esp, eip;
    void* ret_addrs[10];
    jmp_buf buf;
}_fuckit;

int (* orig_raise)(int) ;

int raise(int sig) {
  if (sig==SIGABRT || sig==SIGKILL) {
  } else if (orig_raise){
    orig_raise(sig);
  }
}
void abort() {
  longjmp(_fuckit.buf, 1);
};

static int _disassemble(const uint8_t * bin) {
    ud_set_input_buffer(_fuckit.ud_obj, bin, 10);
    ud_disassemble(_fuckit.ud_obj);
    return ud_insn_len(_fuckit.ud_obj);
}

static void _fuckit_seghandler_userspace() {
  // call backtrace so that if $esp/$ebp is corrupt, we would
  //   fail before decrementing _fuckit.flag
  backtrace(_fuckit.ret_addrs, 2);
  _fuckit.flag--;
  __asm__("leave\n"
  "ret");
}

static void _fuckit_seghandle(int sig, siginfo_t* si, void* unused) {
  static char _in_handler = 0;
  ucontext_t* uc = (ucontext_t*) unused;
  greg_t * gregs = uc->uc_mcontext.gregs;
  void * offending_addr = si->si_addr;
  
  if ((sig != SIGSEGV && sig != SIGBUS) || (void*)gregs[EIP] != offending_addr)
    gregs[EIP] = gregs[EIP] + _disassemble((const uint8_t*)gregs[EIP]);
  else {
    _fuckit.flag ++;
    if (_fuckit.flag <= 1) {
      //_fuckit.esp = (void**)gregs[ESP];
      //_fuckit.eip = (void**)gregs[EIP];
      gregs[EIP] = (greg_t)&_fuckit_seghandler_userspace; //equiv of a jump
    }
    else {
      gregs[EIP] = (greg_t)_fuckit._default_entry;
    }
  }
}

static void _fuckit_setup_segfault_handler() {
  struct sigaction sa;
  sa.sa_flags = SA_SIGINFO;
  sigemptyset (&sa.sa_mask);
  sa.sa_sigaction = &_fuckit_seghandle;
  sigaction(SIGSEGV, &sa, NULL);
  sigaction(SIGBUS, &sa, NULL);
  sigaction(SIGFPE, &sa, NULL);
  sigaction(SIGILL, &sa, NULL);
  sa.sa_sigaction = (void (*)(int, siginfo_t*, void*))SIG_IGN;
  sigaction(SIGABRT, &sa, NULL);
}

static void _fuckit_final() {
    free(_fuckit.ud_obj);
    _fuckit.ud_obj = 0;
}
int fuckit_init() {
    #ifdef dynamic
      orig_raise = dlsym(RTLD_NEXT, "raise");
      _fuckit_dynamic_setup();
    #endif
    void * ptrs[10];
    backtrace(ptrs, 2);
    _fuckit._default_entry = ptrs[1];
    //ptrs[1] is the return point of this function
    _fuckit.ud_obj = (ud_t*)malloc(sizeof(ud_t));
    ud_init(_fuckit.ud_obj);
    ud_set_syntax(_fuckit.ud_obj, UD_SYN_INTEL);
#if __x86_64__
    ud_set_mode(_fuckit.ud_obj, 64);
#else
    ud_set_mode(_fuckit.ud_obj, 32);
#endif

    _fuckit_setup_segfault_handler();
    atexit(_fuckit_final);
    setjmp(&(_fuckit.buf));
}


#if __cplusplus
extern "C"
#endif
void __cxa_throw(void *thrown_exception, void *pvtinfo, void (*dest) (void *) ) {
    // suppress g++ throw routine
}
