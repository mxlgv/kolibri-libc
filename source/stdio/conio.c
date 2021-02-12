#include <conio.h>
#include <ksys.h>

static char* __con_caption = "Console application";
static char* __con_dllname = "/sys/lib/console.obj";

unsigned *__con_dll_ver;
int __con_is_load = 0;

void stdcall (*__con_init_hidden)(int wnd_width, int wnd_height,int scr_width, int scr_height, const char* title);
void stdcall (*__con_exit)(int bCloseWindow);
void stdcall (*__con_set_title)(const char* title);
void stdcall (*__con_write_asciiz)(const char* str);
void stdcall (*__con_write_string)(const char* str, unsigned length);
int cdecl (*__con_printf)(const char* format, ...);
unsigned stdcall (*__con_get_flags)(void);
unsigned stdcall (*__con_set_flags)(unsigned new_flags);
int stdcall (*__con_get_font_height)(void);
int stdcall (*__con_get_cursor_height)(void);
int stdcall (*__con_set_cursor_height)(int new_height);
int stdcall (*__con_getch)(void);
short stdcall (*__con_getch2)(void);
int stdcall (*__con_kbhit)(void);
char* stdcall (*__con_gets)(char* str, int n);
char* stdcall (*__con_gets2)(__con_gets2_callback callback, char* str, int n);
void stdcall (*__con_cls)();
void stdcall (*__con_get_cursor_pos)(int* px, int* py);
void stdcall (*__con_set_cursor_pos)(int x, int y);

static char* __con_imports[] = {
	"START", "version", "__con_init", "__con_write_asciiz", "__con_write_string",
	"__con_printf", "__con_exit", "__con_get_flags", "__con_set_flags", "__con_kbhit",
	"__con_getch", "__con_getch2", "__con_gets", "__con_gets2", "__con_get_font_height",
	"__con_get_cursor_height", "__con_set_cursor_height",  "__con_cls", 
	"__con_get_cursor_pos", "__con_set_cursor_pos", "__con_set_title",
	(char*)0
};

static void __con_lib_link(coff_export_table *exp, char** imports)
{
        __con_dll_ver 		= _ksys_cofflib_getproc(exp, imports[1]);
        __con_init_hidden     = _ksys_cofflib_getproc(exp, imports[2]);
        __con_write_asciiz	= _ksys_cofflib_getproc(exp, imports[3]);
        __con_write_string	= _ksys_cofflib_getproc(exp, imports[4]);
        __con_printf 			= _ksys_cofflib_getproc(exp, imports[5]);
        __con_exit 			= _ksys_cofflib_getproc(exp, imports[6]);
        __con_get_flags 		= _ksys_cofflib_getproc(exp, imports[7]);
        __con_set_flags 		= _ksys_cofflib_getproc(exp, imports[8]);
        __con_kbhit	 		= _ksys_cofflib_getproc(exp, imports[9]);
        __con_getch			= _ksys_cofflib_getproc(exp, imports[10]);
        __con_getch2	 		= _ksys_cofflib_getproc(exp, imports[11]);
        __con_gets	 		= _ksys_cofflib_getproc(exp, imports[12]);
        __con_gets2	 		= _ksys_cofflib_getproc(exp, imports[13]);
        __con_get_font_height	= _ksys_cofflib_getproc(exp, imports[14]);
        __con_get_cursor_height=_ksys_cofflib_getproc(exp, imports[15]);
        __con_set_cursor_height=_ksys_cofflib_getproc(exp, imports[16]);
        __con_cls		 		= _ksys_cofflib_getproc(exp, imports[17]);
        __con_get_cursor_pos	= _ksys_cofflib_getproc(exp, imports[18]);
		__con_set_cursor_pos	= _ksys_cofflib_getproc(exp, imports[19]);
		__con_set_title		= _ksys_cofflib_getproc(exp, imports[20]);
}


int __con_init(void)
{
    return __con_init_opt(-1, -1, -1, -1, __con_caption); 
}


int __con_init_opt(int wnd_width, int wnd_height,int scr_width, int scr_height, const char* title)
{	
    if(!__con_is_load){
        coff_export_table *__con_lib;
	    __con_lib = _ksys_cofflib_load(__con_dllname);
        if(__con_lib==NULL){
            _ksys_debug_puts("Error! Can't load console.obj lib\n");
            return 1;
    	}
    	__con_lib_link(__con_lib, __con_imports);
    	__con_init_hidden(wnd_width, wnd_height, scr_width, scr_height, title); 
    	__con_is_load= 1;
        return 0;
    }
    return 1;
}

