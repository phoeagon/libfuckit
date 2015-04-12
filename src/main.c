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

#include "fuckit.h"
#include <assert.h>
void offending_eip() {    
    __asm__("push $123\n"
    "ret");
}
int main()
{
    static int flag = 0;
    fuckit_init();
    if (!flag)  flag = 1;
    else{
        printf("looping back! exiting\n");
        return 0;
    }
    assert(0);
    printf("recovered 1\n");
    *((int*)123) = 144;
    printf("recovered 2\n");
    *((int*)34) = 144;
    printf("recovered 3\n");
    *((int*)43) = 144;
    printf("recovered 4\n");
    offending_eip();
    printf("recovered 5\n");
    volatile int a = 0;
    a = 4 / a;
    printf("recovered 6\n");
    return 0;
}
