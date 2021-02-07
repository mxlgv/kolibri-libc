/* Initially written by maxcodehack */
#include <ksys.h>
#include <stdio.h>

// ToDo:
// Return 1 if error and 0 if good
void kolibri_init_stdio() {
	coff_export_table *conlib  = _ksys_cofflib_load("/sys/lib/console.obj");
	con_init = _ksys_cofflib_getproc(conlib, "con_init");
	con_printf = _ksys_cofflib_getproc(conlib, "con_printf");
	con_gets = _ksys_cofflib_getproc(conlib, "con_gets");
	con_write_asciiz = _ksys_cofflib_getproc(conlib, "con_write_asciiz");
	
	con_init(-1, -1, -1, -1, "Console application");
}
