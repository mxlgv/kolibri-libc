#ifndef _STDIO_H_
#define _STDIO_H_

/* Initially written by maxcodehack */

#ifndef cdecl
#define cdecl   __attribute__ ((cdecl))
#endif
#ifndef stdcall
#define stdcall __attribute__ ((stdcall))
#endif

void stdcall (*con_init)(int wnd_width, int  wnd_height, int scr_width, int scr_height, const char* title);
int cdecl (*con_printf)(const char* format, ...);
char* stdcall (*con_gets)(char* str, int n);
void stdcall (*con_write_asciiz)(const char* str);

void kolibri_init_stdio();

// ToDo: maybe replace it with normal implementations in other file (printf.c)
#define printf con_printf
#define gets con_gets
#define puts con_write_asciiz

#endif
