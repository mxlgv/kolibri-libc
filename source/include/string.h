#ifndef _STRING_H_
#define _STRING_H_

#include <stddef.h>

void *memcpy(void *dest, const void *source, size_t count);
void *memmove(void *dest, const void *source, size_t count);
void *memset(void *buf, int ch, size_t count);

int strcmp(const char* string1, const char* string2);

#endif