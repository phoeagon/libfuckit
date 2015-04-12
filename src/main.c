#include "fuckit.h"
int main()
{
    _fuckit_init();
    *((int*)123) = 144;
    printf("recovered\n");
    *((int*)34) = 144;
    printf("recovered\n");
    *((int*)43) = 144;
    printf("recovered\n");
    __asm__("push $123\n"
    "ret");
    printf("recovered\n");
    int a = 4 / 0;
    printf("recovered\n");
    return 0;
}
