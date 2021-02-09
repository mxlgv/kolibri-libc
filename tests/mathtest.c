#include <ksys.h>
#include <math.h>

#define cdecl   __attribute__ ((cdecl))
#define stdcall __attribute__ ((stdcall))
 
void stdcall (*con_init)(int wnd_width, int  wnd_height, int scr_width, int scr_height, const char* title);
void stdcall (*puts)(const char* str);
int cdecl (*printf)(const char* format, ...);

int main() {
	coff_export_table *conlib  = _ksys_cofflib_load("/sys/lib/console.obj");
	con_init   =      _ksys_cofflib_getproc(conlib, "con_init");
	puts = _ksys_cofflib_getproc(conlib, "con_write_asciiz");
	printf = _ksys_cofflib_getproc(conlib, "con_printf");

	con_init(-1, -1, -1, -1, "mathtest");
    
	puts("Math testing:\n");
	puts("sqrt(25) = ");
	int a = sqrt(25);
	printf("%d\n", a);
	
	puts("pow(2, 2) = ");
	a = pow(2, 2);
	printf("%d\n", a);
	puts("Done...");
}
