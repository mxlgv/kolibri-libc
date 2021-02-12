#include <stdio.h>
#include <stdlib.h>

#include "conio.h"
#include "format_print.h"

int vprintf ( const char * format, va_list arg )
{
  int len = 0;
  char *s=NULL;
  __con_init();
  s = malloc(4096);
  len = vsnprintf(s, 4096, format, arg);
  __con_write_string(s, len);
  free(s);
  return(len);
}
