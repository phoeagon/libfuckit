#ifndef FUCKIT_DYN_GENERATED_H
#define FUCKIT_DYN_GENERATED_H


    int (*orig_sched_yield)(void);
    int sched_yield(void) {
        int __ret;
        if (orig_sched_yield)
            __ret = orig_sched_yield();
        errno = 0;
        return 0;
    }        
    

    int (*orig_munlockall)(void);
    int munlockall(void) {
        int __ret;
        if (orig_munlockall)
            __ret = orig_munlockall();
        errno = 0;
        return 0;
    }        
    

    int (*orig_fsync)(int p);
    int fsync(int p) {
        int __ret;
        if (orig_fsync)
            __ret = orig_fsync(p);
        errno = 0;
        return 0;
    }        
    

    int (*orig_fdatasync)(int p);
    int fdatasync(int p) {
        int __ret;
        if (orig_fdatasync)
            __ret = orig_fdatasync(p);
        errno = 0;
        return 0;
    }        
    

    int (*orig_close)(int p);
    int close(int p) {
        int __ret;
        if (orig_close)
            __ret = orig_close(p);
        errno = 0;
        return 0;
    }        
    

    int (*orig_nice)(int p);
    int nice(int p) {
        int __ret;
        if (orig_nice)
            __ret = orig_nice(p);
        errno = 0;
        return 0;
    }        
    

    int (*orig_fchdir)(int p);
    int fchdir(int p) {
        int __ret;
        if (orig_fchdir)
            __ret = orig_fchdir(p);
        errno = 0;
        return 0;
    }        
    

    int (*orig_inotify_init1)(int p);
    int inotify_init1(int p) {
        int __ret;
        if (orig_inotify_init1)
            __ret = orig_inotify_init1(p);
        errno = 0;
        return 0;
    }        
    

    int (*orig_mlockall)(int p);
    int mlockall(int p) {
        int __ret;
        if (orig_mlockall)
            __ret = orig_mlockall(p);
        errno = 0;
        return 0;
    }        
    

    int (*orig_chdir)(const char *p);
    int chdir(const char *p) {
        int __ret;
        if (orig_chdir)
            __ret = orig_chdir(p);
        errno = 0;
        return 0;
    }        
    

    int (*orig_rmdir)(const char *p);
    int rmdir(const char *p) {
        int __ret;
        if (orig_rmdir)
            __ret = orig_rmdir(p);
        errno = 0;
        return 0;
    }        
    

    int (*orig_unlink)(const char *p);
    int unlink(const char *p) {
        int __ret;
        if (orig_unlink)
            __ret = orig_unlink(p);
        errno = 0;
        return 0;
    }        
    

    int (*orig_remove)(const char *p);
    int remove(const char *p) {
        int __ret;
        if (orig_remove)
            __ret = orig_remove(p);
        errno = 0;
        return 0;
    }        
    

    int (*orig_fflush)(FILE* f);
    int fflush(FILE* f) {
        int __ret;
        if (orig_fflush)
            __ret = orig_fflush(f);
        errno = 0;
        return 0;
    }        
    

    int (*orig_fclose)(FILE* f);
    int fclose(FILE* f) {
        int __ret;
        if (orig_fclose)
            __ret = orig_fclose(f);
        errno = 0;
        return 0;
    }        
    

    ssize_t (*orig_write)(int fd, const void* buf, size_t len);
    ssize_t write(int fd, const void* buf, size_t len) {
        ssize_t __ret;
        if (orig_write)
            __ret = orig_write(fd, buf, len);
        errno = 0;
        return len;
    }        
    

    ssize_t (*orig_pwrite)(int fd, const void* buf, size_t len, off_t pos);
    ssize_t pwrite(int fd, const void* buf, size_t len, off_t pos) {
        ssize_t __ret;
        if (orig_pwrite)
            __ret = orig_pwrite(fd, buf, len, pos);
        errno = 0;
        return len;
    }        
    

    off_t (*orig_lseek)(int fd, off_t pos, int origin);
    off_t lseek(int fd, off_t pos, int origin) {
        off_t __ret;
        if (orig_lseek)
            __ret = orig_lseek(fd, pos, origin);
        errno = 0;
        return 0;
    }        
    

    int (*orig_ftruncate)(int fd, off_t len);
    int ftruncate(int fd, off_t len) {
        int __ret;
        if (orig_ftruncate)
            __ret = orig_ftruncate(fd, len);
        errno = 0;
        return 0;
    }        
    

    int (*orig_truncate)(const char *path, off_t len);
    int truncate(const char *path, off_t len) {
        int __ret;
        if (orig_truncate)
            __ret = orig_truncate(path, len);
        errno = 0;
        return 0;
    }        
    

    ssize_t (*orig_writev)(int fd, const struct iovec *iov, int count);
    ssize_t writev(int fd, const struct iovec *iov, int count) {
        ssize_t __ret;
        if (orig_writev)
            __ret = orig_writev(fd, iov, count);
        errno = 0;
        return 0;
    }        
    

    int (*orig_fchmod)(int fd, mode_t mode);
    int fchmod(int fd, mode_t mode) {
        int __ret;
        if (orig_fchmod)
            __ret = orig_fchmod(fd, mode);
        errno = 0;
        return 0;
    }        
    

    int (*orig_chmod)(const char *path, mode_t mode);
    int chmod(const char *path, mode_t mode) {
        int __ret;
        if (orig_chmod)
            __ret = orig_chmod(path, mode);
        errno = 0;
        return 0;
    }        
    

    int (*orig_chown)(const char *path, uid_t owner, gid_t group);
    int chown(const char *path, uid_t owner, gid_t group) {
        int __ret;
        if (orig_chown)
            __ret = orig_chown(path, owner, group);
        errno = 0;
        return 0;
    }        
    

    int (*orig_lchown)(const char *path, uid_t owner, gid_t group);
    int lchown(const char *path, uid_t owner, gid_t group) {
        int __ret;
        if (orig_lchown)
            __ret = orig_lchown(path, owner, group);
        errno = 0;
        return 0;
    }        
    

    int (*orig_fchown)(int fd, uid_t owner, gid_t group);
    int fchown(int fd, uid_t owner, gid_t group) {
        int __ret;
        if (orig_fchown)
            __ret = orig_fchown(fd, owner, group);
        errno = 0;
        return 0;
    }        
    

    int (*orig_closedir)(DIR *dir);
    int closedir(DIR *dir) {
        int __ret;
        if (orig_closedir)
            __ret = orig_closedir(dir);
        errno = 0;
        return 0;
    }        
    

    int (*orig_link)(const char* p, const char *q);
    int link(const char* p, const char *q) {
        int __ret;
        if (orig_link)
            __ret = orig_link(p, q);
        errno = 0;
        return 0;
    }        
    

    int (*orig_symlink)(const char* p, const char *q);
    int symlink(const char* p, const char *q) {
        int __ret;
        if (orig_symlink)
            __ret = orig_symlink(p, q);
        errno = 0;
        return 0;
    }        
    

    int (*orig_rename)(const char* p, const char *q);
    int rename(const char* p, const char *q) {
        int __ret;
        if (orig_rename)
            __ret = orig_rename(p, q);
        errno = 0;
        return 0;
    }        
    

    int (*orig_inotify_rm_watch)(int fd, int wd);
    int inotify_rm_watch(int fd, int wd) {
        int __ret;
        if (orig_inotify_rm_watch)
            __ret = orig_inotify_rm_watch(fd, wd);
        errno = 0;
        return 0;
    }        
    

    int (*orig_brk)(void* end);
    int brk(void* end) {
        int __ret;
        if (orig_brk)
            __ret = orig_brk(end);
        errno = 0;
        return 0;
    }        
    

    void* (*orig_sbrk)(intptr_t increment);
    void* sbrk(intptr_t increment) {
        void* __ret;
        if (orig_sbrk)
            __ret = orig_sbrk(increment);
        errno = 0;
        return __ret;
    }        
    

    int (*orig_stime)(const time_t *t);
    int stime(const time_t *t) {
        int __ret;
        if (orig_stime)
            __ret = orig_stime(t);
        errno = 0;
        return 0;
    }        
    

    int* (*orig_mlock)(const void *addr, size_t len);
    int* mlock(const void *addr, size_t len) {
        int* __ret;
        if (orig_mlock)
            __ret = orig_mlock(addr, len);
        errno = 0;
        return 0;
    }        
    

    int* (*orig_munlock)(const void *addr, size_t len);
    int* munlock(const void *addr, size_t len) {
        int* __ret;
        if (orig_munlock)
            __ret = orig_munlock(addr, len);
        errno = 0;
        return 0;
    }        
    

    void _fuckit_dyn_init_generated() {
        printf("_fuckit_dyn_init_generated()\n");
        orig_sched_yield=dlsym(RTLD_NEXT, "sched_yield");
        #ifdef VERBOSE
 printf("%s: %p\n", "sched_yield", orig_sched_yield);
 #endif
;
        orig_munlockall=dlsym(RTLD_NEXT, "munlockall");
        #ifdef VERBOSE
 printf("%s: %p\n", "munlockall", orig_munlockall);
 #endif
;
        orig_fsync=dlsym(RTLD_NEXT, "fsync");
        #ifdef VERBOSE
 printf("%s: %p\n", "fsync", orig_fsync);
 #endif
;
        orig_fdatasync=dlsym(RTLD_NEXT, "fdatasync");
        #ifdef VERBOSE
 printf("%s: %p\n", "fdatasync", orig_fdatasync);
 #endif
;
        orig_close=dlsym(RTLD_NEXT, "close");
        #ifdef VERBOSE
 printf("%s: %p\n", "close", orig_close);
 #endif
;
        orig_nice=dlsym(RTLD_NEXT, "nice");
        #ifdef VERBOSE
 printf("%s: %p\n", "nice", orig_nice);
 #endif
;
        orig_fchdir=dlsym(RTLD_NEXT, "fchdir");
        #ifdef VERBOSE
 printf("%s: %p\n", "fchdir", orig_fchdir);
 #endif
;
        orig_inotify_init1=dlsym(RTLD_NEXT, "inotify_init1");
        #ifdef VERBOSE
 printf("%s: %p\n", "inotify_init1", orig_inotify_init1);
 #endif
;
        orig_mlockall=dlsym(RTLD_NEXT, "mlockall");
        #ifdef VERBOSE
 printf("%s: %p\n", "mlockall", orig_mlockall);
 #endif
;
        orig_chdir=dlsym(RTLD_NEXT, "chdir");
        #ifdef VERBOSE
 printf("%s: %p\n", "chdir", orig_chdir);
 #endif
;
        orig_rmdir=dlsym(RTLD_NEXT, "rmdir");
        #ifdef VERBOSE
 printf("%s: %p\n", "rmdir", orig_rmdir);
 #endif
;
        orig_unlink=dlsym(RTLD_NEXT, "unlink");
        #ifdef VERBOSE
 printf("%s: %p\n", "unlink", orig_unlink);
 #endif
;
        orig_remove=dlsym(RTLD_NEXT, "remove");
        #ifdef VERBOSE
 printf("%s: %p\n", "remove", orig_remove);
 #endif
;
        orig_fflush=dlsym(RTLD_NEXT, "fflush");
        #ifdef VERBOSE
 printf("%s: %p\n", "fflush", orig_fflush);
 #endif
;
        orig_fclose=dlsym(RTLD_NEXT, "fclose");
        #ifdef VERBOSE
 printf("%s: %p\n", "fclose", orig_fclose);
 #endif
;
        orig_write=dlsym(RTLD_NEXT, "write");
        #ifdef VERBOSE
 printf("%s: %p\n", "write", orig_write);
 #endif
;
        orig_pwrite=dlsym(RTLD_NEXT, "pwrite");
        #ifdef VERBOSE
 printf("%s: %p\n", "pwrite", orig_pwrite);
 #endif
;
        orig_lseek=dlsym(RTLD_NEXT, "lseek");
        #ifdef VERBOSE
 printf("%s: %p\n", "lseek", orig_lseek);
 #endif
;
        orig_ftruncate=dlsym(RTLD_NEXT, "ftruncate");
        #ifdef VERBOSE
 printf("%s: %p\n", "ftruncate", orig_ftruncate);
 #endif
;
        orig_truncate=dlsym(RTLD_NEXT, "truncate");
        #ifdef VERBOSE
 printf("%s: %p\n", "truncate", orig_truncate);
 #endif
;
        orig_writev=dlsym(RTLD_NEXT, "writev");
        #ifdef VERBOSE
 printf("%s: %p\n", "writev", orig_writev);
 #endif
;
        orig_fchmod=dlsym(RTLD_NEXT, "fchmod");
        #ifdef VERBOSE
 printf("%s: %p\n", "fchmod", orig_fchmod);
 #endif
;
        orig_chmod=dlsym(RTLD_NEXT, "chmod");
        #ifdef VERBOSE
 printf("%s: %p\n", "chmod", orig_chmod);
 #endif
;
        orig_chown=dlsym(RTLD_NEXT, "chown");
        #ifdef VERBOSE
 printf("%s: %p\n", "chown", orig_chown);
 #endif
;
        orig_lchown=dlsym(RTLD_NEXT, "lchown");
        #ifdef VERBOSE
 printf("%s: %p\n", "lchown", orig_lchown);
 #endif
;
        orig_fchown=dlsym(RTLD_NEXT, "fchown");
        #ifdef VERBOSE
 printf("%s: %p\n", "fchown", orig_fchown);
 #endif
;
        orig_closedir=dlsym(RTLD_NEXT, "closedir");
        #ifdef VERBOSE
 printf("%s: %p\n", "closedir", orig_closedir);
 #endif
;
        orig_link=dlsym(RTLD_NEXT, "link");
        #ifdef VERBOSE
 printf("%s: %p\n", "link", orig_link);
 #endif
;
        orig_symlink=dlsym(RTLD_NEXT, "symlink");
        #ifdef VERBOSE
 printf("%s: %p\n", "symlink", orig_symlink);
 #endif
;
        orig_rename=dlsym(RTLD_NEXT, "rename");
        #ifdef VERBOSE
 printf("%s: %p\n", "rename", orig_rename);
 #endif
;
        orig_inotify_rm_watch=dlsym(RTLD_NEXT, "inotify_rm_watch");
        #ifdef VERBOSE
 printf("%s: %p\n", "inotify_rm_watch", orig_inotify_rm_watch);
 #endif
;
        orig_brk=dlsym(RTLD_NEXT, "brk");
        #ifdef VERBOSE
 printf("%s: %p\n", "brk", orig_brk);
 #endif
;
        orig_sbrk=dlsym(RTLD_NEXT, "sbrk");
        #ifdef VERBOSE
 printf("%s: %p\n", "sbrk", orig_sbrk);
 #endif
;
        orig_stime=dlsym(RTLD_NEXT, "stime");
        #ifdef VERBOSE
 printf("%s: %p\n", "stime", orig_stime);
 #endif
;
        orig_mlock=dlsym(RTLD_NEXT, "mlock");
        #ifdef VERBOSE
 printf("%s: %p\n", "mlock", orig_mlock);
 #endif
;
        orig_munlock=dlsym(RTLD_NEXT, "munlock");
        #ifdef VERBOSE
 printf("%s: %p\n", "munlock", orig_munlock);
 #endif
;
    }
    
#endif
