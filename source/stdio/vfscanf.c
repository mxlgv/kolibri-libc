#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "format_scan.h"

static int __virtual_getc_file(void *sp, const void *obj)
{
    FILE *f = (FILE *)obj;
    int ch = fgetc(f);
    return ch;
}

static void __virtual_ungetc_file(void *sp, int c, const void *obj)
{
    FILE *f = (FILE *)obj;
    if (f) ungetc(c, f);
}


int vfscanf(FILE * stream, const char * format, va_list arg)
{
    return _format_scan(stream, format, arg, &__virtual_getc_file, &__virtual_ungetc_file);
}