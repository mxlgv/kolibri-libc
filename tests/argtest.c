#include <ksys.h>
#include <string.h>

#define cdecl   __attribute__ ((cdecl))
#define stdcall __attribute__ ((stdcall))
 
void stdcall (*con_init)(int wnd_width, int  wnd_height, int scr_width, int scr_height, const char* title);
void stdcall (*con_write_asciiz)(const char* str);

void reverse(char s[]) {
    int i, j; char c;
    for (i = 0, j = strlen(s)-1; i<j; i++, j--) { c = s[i]; s[i] = s[j]; s[j] = c; }
}

void itoa(int n, char s[]) {
    int i, sign; i = 0;
    if ((sign = n) < 0) n = -n;
    do { s[i++] = n % 10 + '0'; } while ((n /= 10) > 0); 
    if (sign < 0) s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main(int argc, char** argv) {
    char buf[16];
    int i;

    coff_export_table *conlib  = _ksys_cofflib_load("/sys/lib/console.obj");
    con_init   =      _ksys_cofflib_getproc(conlib, "con_init");
    con_write_asciiz = _ksys_cofflib_getproc(conlib, "con_write_asciiz");
    
    con_init(-1, -1, -1, -1, "argtest");
    
    con_write_asciiz("argc = ");
    itoa(argc, buf);
    con_write_asciiz(buf);
    con_write_asciiz("\n");

    con_write_asciiz("Argument array:\n");

    for (i = 0; i < argc; i++) {
        con_write_asciiz("argv[");
        itoa(i, buf);
        con_write_asciiz(buf);
        con_write_asciiz("] = ");
        con_write_asciiz(argv[i]);
        con_write_asciiz("\n");
    }
    return 0;
 }
