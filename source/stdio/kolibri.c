/* Initially written by maxcodehack */
#include <ksys.h>
#include <stdio.h>

// ToDo:
// Return 1 if error and 0 if good
void kolibri_init_stdio() {
	coff_export_table *conlib  = _ksys_cofflib_load("/sys/lib/console.obj");
	con_init = _ksys_cofflib_getproc(conlib, "con_init");
	
	printf = _ksys_cofflib_getproc(conlib, "con_printf");
	gets = _ksys_cofflib_getproc(conlib, "con_gets");
	puts = _ksys_cofflib_getproc(conlib, "con_write_asciiz");
	
	con_init(-1, -1, -1, -1, "Console application");
}
