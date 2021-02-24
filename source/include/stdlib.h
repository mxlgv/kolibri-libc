#ifndef _STDLIB_H_
#define _STDLIB_H_

#include <stddef.h>

#define RAND_MAX        65535
#ifndef NULL
# define NULL ((void*)0)
#endif
 
#define min(a, b) ((a)<(b) ? (a) : (b))
#define max(a, b) ((a)>(b) ? (a) : (b))

int  _FUNC(atoi)(const char *s);
long _FUNC(atol)(const char *);
long long _FUNC(atoll)(const char *);
//char* itoa)(int n, char* s);

int _FUNC(abs)(int);
long _FUNC(labs)(long);
long long _FUNC(llabs)(long long);

typedef struct { int quot, rem; } div_t;
typedef struct { long quot, rem; } ldiv_t;
typedef struct { long long quot, rem; } lldiv_t;

div_t _FUNC(div)(int, int);
ldiv_t _FUNC(ldiv)(long, long);
lldiv_t _FUNC(lldiv)(long long, long long);

void  _FUNC(*malloc)(size_t size);
void* _FUNC(calloc)(size_t num, size_t size);
void* _FUNC(realloc)(void *ptr, size_t newsize);
void  _FUNC(free)(void *ptr);

void  _FUNC(exit)(int status);

#endif