#include <stdio.h>

int main() {
       kolibri_init_stdio();
       char name[250];
       gets(name, 250);
       puts("Your name is ");
       puts(name);
       printf("\n---\nSmall libc, written in %d!", 2021);
}
