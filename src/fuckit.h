/*
 * Copyright 2015 phoeagon

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
* 
*/

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
