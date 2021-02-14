#include <stdio.h>

int fclose(FILE *stream) {
	free(stream);
	return 0;
}
