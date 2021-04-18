#include <sys/ksys.h>
#include <stdio.h>
#include <limits.h>

char* test_string1 = "Hello world!";
/*
void my_panic(char* func_name){
    _ksys_debug_puts("Panic!\n");
    _ksys_exit();
}

int (*puts)(const char *str);
int (*printf)(const char* format, ...);
*/

int main(int argc, char** argv){
/*    ksys_coff_etable_t *libc = _ksys_load_coff("/sys/lib/libc.obj");
    if(!libc){
        _ksys_debug_puts("Error! libc.obj not loaded!\n");
    }
    printf = _ksys_get_coff_func(libc, "printf", my_panic);
    puts = _ksys_get_coff_func(libc, "puts", my_panic);*/
    printf("Hello world! = %s\n", test_string1);
    printf("345.358980 = %f\n", 345.35898);
    printf("345 = %d\n", (int)345.35898);
    printf("ff = %x\n", 255);
    printf("-1 = %d\n", UINT_MAX);
    printf("5A-4B-N$ = %s%c-%u%c-N%c\n", "5", 'A', 4, 'B', '$');
    puts("Done!");
    return 0;
}
