#include <ksys.h>

unsigned _ksys_get_clock()
{
    unsigned val;
    asm_inline("int $0x40":"=a"(val):"a"(3));
    return val;
}
