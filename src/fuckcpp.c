#include "fuckcpp.h"

void _fuckcpp_seghandle(int sig, siginfo_t* si, void* unused) {
  static char _in_handler = 0;
  ucontext_t* uc = (ucontext_t*) unused;
  greg_t * gregs = uc->uc_mcontext.gregs;
  void * offending_addr = si->si_addr;
#if __x86_64__
  if ((sig != SIGSEGV && sig != SIGBUS) || gregs[REG_RIP] != offending_addr)
    gregs[REG_RIP] = gregs[REG_RIP] + disassemble(gregs[REG_RIP]);
  else
    gregs[REG_RIP] = _fuckcpp._default_entry;
#else
  if ((sig != SIGSEGV && sig != SIGBUS) || gregs[REG_EIP] != offending_addr)
    gregs[REG_EIP] = gregs[REG_EIP] + disassemble(gregs[REG_EIP]);
  else
    gregs[REG_EIP] = _fuckcpp._default_entry;
#endif

}
void _fuckcpp_setup_segfault_handler() {
  struct sigaction sa;
  sa.sa_flags = SA_SIGINFO;
  sigemptyset (&sa.sa_mask);
  sa.sa_sigaction = &_fuckcpp_seghandle;
  sigaction(SIGSEGV, &sa, NULL);
  sigaction(SIGBUS, &sa, NULL);
  sigaction(SIGFPE, &sa, NULL);
  sigaction(SIGILL, &sa, NULL);
}

void _fuckcpp_final() {
    free(_fuckcpp.ud_obj);
    _fuckcpp.ud_obj = 0;
}
int _fuckcpp_init() {
    void * ptrs[10];
    backtrace(ptrs, 2);
    _fuckcpp._default_entry = ptrs[1];
    //ptrs[1] is the return point of this function
    _fuckcpp.ud_obj = (ud_t*)malloc(sizeof(ud_t));
    ud_init(_fuckcpp.ud_obj);
    ud_set_syntax(_fuckcpp.ud_obj, UD_SYN_INTEL);
#if __x86_64__
    ud_set_mode(_fuckcpp.ud_obj, 64);
#else
    ud_set_mode(_fuckcpp.ud_obj, 32);
#endif

    _fuckcpp_setup_segfault_handler();
    atexit(_fuckcpp_final);
}
int disassemble(const uint8_t * bin) {
    ud_set_input_buffer(_fuckcpp.ud_obj, bin, 10);
    ud_disassemble(_fuckcpp.ud_obj);
    return ud_insn_len(_fuckcpp.ud_obj);
}
