#include <ksys.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

int puts(const char *str)
{
    __con_init();
    __con_write_asciiz(str);
    __con_write_asciiz("\n");
    return strlen(str);
}