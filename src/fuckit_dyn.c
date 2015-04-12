#ifdef dynamic
#define _GNU_SOURCE
#include <dlfcn.h>
#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/uio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/inotify.h>
#include <time.h>

void _fuckit_dyn_init_generated() ;


void (*orig_exit)(int p);
void exit(int p) {
    if (orig_exit)
        orig_exit(0);
    errno = 0;
}

int _fuckit_dynamic_setup() {
    orig_exit=dlsym(RTLD_NEXT, "exit");
    _fuckit_dyn_init_generated();
}

#include "fuckit_dyn_generated.h"

#endif
