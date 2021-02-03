#include <stdlib.h>
#include <kos32sys1.h>

void free(void *ptr) {
    int res;
    __asm__ __volatile__( "int $0x40" :"=a"(res) :"a"(68),"b"(13),"c"(ptr));
    ((void)res);
}