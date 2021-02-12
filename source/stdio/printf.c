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
