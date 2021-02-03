#include <stdlib.h>
#include <kos32sys1.h>


void *calloc(size_t num, size_t size) {
    void  *res;
    __asm__ __volatile__( "int $0x40" :"=a"(res) :"a"(68),"b"(12),"c"(num*size) : "memory");
    return res;
}