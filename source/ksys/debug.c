#include <ksys.h>

void _ksys_debug_putc(char c)
{
    asm_inline("int $0x40"::"a"(63), "b"(1), "c"(c));
}
 
 
void _ksys_debug_puts(char *s)
{
    unsigned i=0;
    while (*(s+i)){
        asm_inline ("int $0x40"::"a"(63), "b"(1), "c"(*(s+i)));
        i++;
    }
}
 