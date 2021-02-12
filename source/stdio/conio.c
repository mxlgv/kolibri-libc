#include <conio.h>
#include <ksys.h>

static char* con_caption = "Console application";
static char* con_dllname = "/sys/lib/console.obj";

unsigned *con_dll_ver;
int con_is_load = 0;

void stdcall (*con_init_hidden)(int wnd_width, int wnd_height,int scr_width, int scr_height, const char* title);
void stdcall (*con_exit)(int bCloseWindow);
void stdcall (*con_set_title)(const char* title);
void stdcall (*con_write_asciiz)(const char* str);
void stdcall (*con_write_string)(const char* str, unsigned length);
int cdecl (*con_printf)(const char* format, ...);
unsigned stdcall (*con_get_flags)(void);
unsigned stdcall (*con_set_flags)(unsigned new_flags);
int stdcall (*con_get_font_height)(void);
int stdcall (*con_get_cursor_height)(void);
int stdcall (*con_set_cursor_height)(int new_height);
int stdcall (*con_getch)(void);
short stdcall (*con_getch2)(void);
int stdcall (*con_kbhit)(void);
char* stdcall (*con_gets)(char* str, int n);
char* stdcall (*con_gets2)(con_gets2_callback callback, char* str, int n);
void stdcall (*con_cls)();
void stdcall (*con_get_cursor_pos)(int* px, int* py);
void stdcall (*con_set_cursor_pos)(int x, int y);

static char* con_imports[] = {
	"START", "version", "con_init", "con_write_asciiz", "con_write_string",
	"con_printf", "con_exit", "con_get_flags", "con_set_flags", "con_kbhit",
	"con_getch", "con_getch2", "con_gets", "con_gets2", "con_get_font_height",
	"con_get_cursor_height", "con_set_cursor_height",  "con_cls", 
	"con_get_cursor_pos", "con_set_cursor_pos", "con_set_title",
	(char*)0
};

static void con_lib_link(coff_export_table *exp, char** imports)
{
        con_dll_ver 		= _ksys_cofflib_getproc(exp, imports[1]);
        con_init_hidden     = _ksys_cofflib_getproc(exp, imports[2]);
        con_write_asciiz	= _ksys_cofflib_getproc(exp, imports[3]);
        con_write_string	= _ksys_cofflib_getproc(exp, imports[4]);
        con_printf 			= _ksys_cofflib_getproc(exp, imports[5]);
        con_exit 			= _ksys_cofflib_getproc(exp, imports[6]);
        con_get_flags 		= _ksys_cofflib_getproc(exp, imports[7]);
        con_set_flags 		= _ksys_cofflib_getproc(exp, imports[8]);
        con_kbhit	 		= _ksys_cofflib_getproc(exp, imports[9]);
        con_getch			= _ksys_cofflib_getproc(exp, imports[10]);
        con_getch2	 		= _ksys_cofflib_getproc(exp, imports[11]);
        con_gets	 		= _ksys_cofflib_getproc(exp, imports[12]);
        con_gets2	 		= _ksys_cofflib_getproc(exp, imports[13]);
        con_get_font_height	= _ksys_cofflib_getproc(exp, imports[14]);
        con_get_cursor_height=_ksys_cofflib_getproc(exp, imports[15]);
        con_set_cursor_height=_ksys_cofflib_getproc(exp, imports[16]);
        con_cls		 		= _ksys_cofflib_getproc(exp, imports[17]);
        con_get_cursor_pos	= _ksys_cofflib_getproc(exp, imports[18]);
		con_set_cursor_pos	= _ksys_cofflib_getproc(exp, imports[19]);
		con_set_title		= _ksys_cofflib_getproc(exp, imports[20]);
}


int con_init(void)
{
    return con_init_opt(-1, -1, -1, -1, con_caption); 
}


int con_init_opt(int wnd_width, int wnd_height,int scr_width, int scr_height, const char* title)
{	
    if(!con_is_load){
        coff_export_table *con_lib;
	    con_lib = _ksys_cofflib_load(con_dllname);
        if(con_lib==NULL){
            _ksys_debug_puts("Error! Can't load console.obj lib\n");
            return 1;
    	}
    	con_lib_link(con_lib, con_imports);
    	con_init_hidden(wnd_width, wnd_height, scr_width, scr_height, title); 
    	con_is_load= 1;
        return 0;
    }
    return 1;
}

