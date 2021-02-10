#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "format_print.h"

int printf(const char *format, ...)
{
  va_list arg;
  va_start(arg, format);
  return vprintf(format, arg);
}

int vprintf ( const char * format, va_list arg )
{
  int len = 0;
  char *s=NULL;
  con_init();
  s = malloc(4096);
  len = vsnprintf(s, 4096, format, arg);
  con_write_string(s, len);
  free(s);
  return(len);
}