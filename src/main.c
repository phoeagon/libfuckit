#include "fuckit.h"
#include <assert.h>
int main()
{
    static int flag = 0;
    fuckit_init();
    if (!flag)  flag = 1;
    else{
        printf("successfully looping back! exiting\n");
        return 0;
    }
    assert(0);
    printf("recovered\n");
    *((int*)123) = 144;
    printf("recovered\n");
    *((int*)34) = 144;
    printf("recovered\n");
    *((int*)43) = 144;
    printf("recovered\n");
    __asm__("push $123\n"
    "ret");
    printf("recovered\n");
    volatile int a = 0;
    a = 4 / a; // this one would cause loop back to main
    printf("recovered\n");
    return 0;
}
