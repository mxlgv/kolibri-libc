#include <stdlib.h>
#include <kos32sys1.h>

void *realloc(void *ptr, size_t newsize) {
    void *res;
    __asm__ __volatile__( "int $0x40" :"=a"(res) :"a"(68),"b"(20),"c"(newsize),"d"(ptr) :"memory");
    return res;
}