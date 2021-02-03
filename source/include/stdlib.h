#ifndef _STDLIB_H_
#define _STDLIB_H_

#include <stddef.h>

#define RAND_MAX        65535
#ifndef NULL
# define NULL ((void*)0)
#endif
 
#define abs(i) (((i)<0)?(-(i)):(i))
#define labs(li) abs(li)
 
#define min(a, b) ((a)<(b) ? (a) : (b))
#define max(a, b) ((a)>(b) ? (a) : (b))


void *malloc(size_t size);
void *calloc(size_t num, size_t size);
void *realloc(void *ptr, size_t newsize);
void free(void *ptr);

int atoi(char *s);

#endif