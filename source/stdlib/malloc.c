#include <stdlib.h>
#include <sys/kolibri.h>

void *malloc(size_t size) {
    void  *res;
    __asm__ __volatile__( "int $0x40" :"=a"(res) :"a"(68),"b"(12),"c"(size) : "memory");
    return res;
}