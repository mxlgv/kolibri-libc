#include <ksys.h>

unsigned _ksys_get_date()
{
    unsigned val;
    asm_inline("int $0x40":"=a"(val):"a"(29));
    return val;
}