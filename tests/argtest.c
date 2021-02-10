#include <ksys.h>
#include <string.h>
#include <conio.h>

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
    
    con_init_console_dll();    
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
