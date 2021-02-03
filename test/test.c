#include <ksys.h>

#define cdecl   __attribute__ ((cdecl))
#define stdcall __attribute__ ((stdcall))
 
 void stdcall (*con_init)(int wnd_width, int  wnd_height, int scr_width, int scr_height, const char* title);
 void stdcall (*con_write_asciiz)(const char* str);

 int main(){
       coff_export_table *conlib  = _ksys_cofflib_load("/sys/lib/console.obj");
       con_init   =      _ksys_cofflib_getproc(conlib, "con_init");
       con_write_asciiz = _ksys_cofflib_getproc(conlib, "con_write_asciiz");
       
       con_init(-1, -1, -1, -1, "test");
       con_write_asciiz("Hello!");

 }
