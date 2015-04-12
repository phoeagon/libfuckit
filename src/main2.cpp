#include "fuckit.h"
#include <cstdio>
#include <string>
#include <bitset>

int main()
{
    fuckit_init();
    throw std::string("");
    printf("recovered\n");
    // should even work even if we undefine the throw
    #undef throw
    throw std::string("");
    printf("recovered\n");
    std::bitset<100> bs;
    bs.set(80);
    u_int32_t a = bs.to_ulong(); //throw overflow
    printf("recovered\n");
    printf("finished\n");
    return 0;
}
