#include <ksys.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

int puts(const char *str)
{
    con_init();
    con_write_asciiz(str);
    con_write_asciiz("\n");
    return strlen(str);
}