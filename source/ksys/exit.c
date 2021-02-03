#include <ksys.h>

void _ksys_exit()
{
    asm_inline("int $0x40"::"a"(-1));
}
 