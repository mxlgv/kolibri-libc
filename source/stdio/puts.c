#include <stdio.h>
#include <string.h>

#include "conio.h"

int puts(const char *str)
{
    __con_init();
    __con_write_asciiz(str);
    __con_write_asciiz("\n");
    return strlen(str);
}