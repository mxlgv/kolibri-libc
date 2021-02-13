#include <ksys.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    char test_stack[1000000];
    printf("argc = %d\n", argc);
    puts("Argument array:");

    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);    
    }
    debug_printf("Done!\n");
    exit(0);
 }
