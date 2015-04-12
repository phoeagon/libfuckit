#include "fuckit.h"
#include "stdio.h"
#include "errno.h"

int main(){
    fuckit_init();
    int ret = fflush((FILE*)10);
    printf("%d %d\n", errno, ret);
    ret = close(10);
    printf("%d %d\n", errno, ret);
    return 0;
}
