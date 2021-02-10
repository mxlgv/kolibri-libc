#include <ksys.h>
#include <conio.h>
#include <math.h>

int main() {
	con_init_console_dll();
	con_write_asciiz("Math testing:\n");
	con_printf("sqrt(25) = %d\n", (int)sqrt(25));
	con_printf("pow(2, 2) = %d\n", (int)pow(2, 2));
	con_exit(0);
	return 0;
}
