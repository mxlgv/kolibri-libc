#include <string.h>

void *memmove(void *dest, const void *source, size_t count) {
    char *dst = dst_void;
    const char *src = src_void;
    if (src < dst && dst < src + length) {
        /* Have to copy backwards */
        src += length;
        dst += length;
        while (length--) {
              *--dst = *--src;
        }
    } else {
        while (length--) {
            *dst++ = *src++;
        }
    }
    return dst_void;
}