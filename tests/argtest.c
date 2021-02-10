#include <ksys.h>
#include <string.h>
#include <stdio.h>

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
    itoa(argc, buf);
    printf("argc = %s\n", buf);
    printf("Argument array:\n");

    for (i = 0; i < argc; i++) {
        itoa(i, buf);
        printf("argv[%s] = %d\n", argv[i]);
    }
    return 0;
 }
