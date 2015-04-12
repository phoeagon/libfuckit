#!/usr/local/env python


init_statements = []

def generate(rettype, retval, params, args, name):
    global init_statements
    print """
    <<T>> (*orig_<<C>>)(<<P>>);
    <<T>> <<C>>(<<P>>) {
        <<T>> __ret;
        if (orig_<<C>>)
            __ret = orig_<<C>>(<<A>>);
        errno = 0;
        return <<V>>;
    }        
    """.replace('<<T>>', rettype).replace('<<V>>', retval) \
    .replace('<<P>>', params).replace('<<A>>', args).replace('<<C>>', name)
    init_statements.append("orig_<<C>>=dlsym(RTLD_NEXT, \"<<C>>\")".replace('<<C>>', name))
    init_statements.append("#ifdef VERBOSE\n printf(\"%s: %p\\n\", \"<<C>>\", orig_<<C>>);\n #endif\n".replace('<<C>>', name))

def generate_one_int_to_one_int():
    for call in ['sched_yield', 'munlockall']:
        generate("int", "0", "void", "", call)
    for call in ['fsync', 'fdatasync', 'close', 'nice', 'fchdir', 'inotify_init1', 'mlockall']:
        generate("int", "0", "int p", "p", call)
    for call in ['chdir', 'rmdir', 'unlink', 'remove']:
        generate("int", "0", "const char *p", "p", call)
    for call in ['fflush', 'fclose']:
        generate("int", "0", "FILE* f", "f", call)
    generate("ssize_t", "len", "int fd, const void* buf, size_t len", "fd, buf, len", "write")
    generate("ssize_t", "len",
             "int fd, const void* buf, size_t len, off_t pos",
             "fd, buf, len, pos", "pwrite")
    generate("off_t", "0", "int fd, off_t pos, int origin", "fd, pos, origin", "lseek")
    generate("int", "0", "int fd, off_t len", "fd, len", "ftruncate")
    generate("int", "0", "const char *path, off_t len", "path, len", "truncate")
    generate("ssize_t", "0", "int fd, const struct iovec *iov, int count", "fd, iov, count", "writev")
    generate("int", "0", "int fd, mode_t mode", "fd, mode", "fchmod")
    generate("int", "0", "const char *path, mode_t mode", "path, mode", "chmod")
    generate("int", "0", "const char *path, uid_t owner, gid_t group", "path, owner, group", "chown")
    generate("int", "0", "const char *path, uid_t owner, gid_t group", "path, owner, group", "lchown")
    generate("int", "0", "int fd, uid_t owner, gid_t group", "fd, owner, group", "fchown")
    generate("int", "0","DIR *dir", "dir", "closedir")
    for call in ['link', 'symlink', 'rename']:
        generate("int", "0", "const char* p, const char *q", "p, q", call)
    generate("int", "0","int fd, int wd", "fd, wd", "inotify_rm_watch")
    generate("int", "0", "void* end", "end", "brk")
    generate("void*", "__ret", "intptr_t increment", "increment", "sbrk")
    generate("int", "0", "const time_t *t", "t", "stime")
    for call in ['mlock', 'munlock']:
        generate("int*", "0", "const void *addr, size_t len", "addr, len", call)

def main():
    print "#ifndef FUCKIT_DYN_GENERATED_H"
    print "#define FUCKIT_DYN_GENERATED_H"
    print ""
    generate_one_int_to_one_int()
    print """
    void _fuckit_dyn_init_generated() {
        printf(\"_fuckit_dyn_init_generated()\\n\");
        %s;
    }
    """ % (';\n        '.join(init_statements))
    print "#endif"

if __name__ == '__main__':
    main()
