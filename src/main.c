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
