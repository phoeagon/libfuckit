#ifndef FUCKCPP_H
#define FUCKCPP_H

#define _GNU_SOURCE
#include <stdio.h>
#include <udis86.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <ucontext.h>
#include <execinfo.h>


struct fuckcpp_t {
    void* _default_entry;
    ud_t * ud_obj;
}_fuckit;

int fuckit_init();
#endif
