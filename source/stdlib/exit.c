#include "../stdio/conio.h"
#include <ksys.h>

void exit(int status)
{
    if(__con_is_load){
        __con_exit(status);
    }
    _ksys_exit();
}
