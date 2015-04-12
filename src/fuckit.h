#ifndef FUCKCPP_H
#define FUCKCPP_H

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <stdio.h>
#include <udis86.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <ucontext.h>
#include <execinfo.h>


#if __cplusplus
extern "C"
#endif
int fuckit_init();

// disable throw
#if __cplusplus
    //#define throw sizeof
typedef void (*cxa_throw_type)(void* , void *, void (*) (void *));
extern "C" 
#endif
void __cxa_throw(void *thrown_exception, void *pvtinfo, void (*dest) (void *) );
//__cxa_throw is used by clang++ & g++

// Disable assert
#define NDEBUG 
#undef assert
#define assert(x) (1)

#endif
