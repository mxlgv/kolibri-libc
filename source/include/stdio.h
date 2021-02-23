///////////////////////////////////////////////////////////////////////////////
// \author (c) Marco Paland (info@paland.com)
//             2014-2019, PALANDesign Hannover, Germany
//
// \license The MIT License (MIT)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// \brief Tiny printf, sprintf and snprintf implementation, optimized for speed on
//        embedded systems with a very limited resources.
//        Use this instead of bloated standard/newlib printf.
//        These routines are thread safe and reentrant.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef _STDIO_H_
#define _STDIO_H_

#include <stdarg.h>
#include <stddef.h>
#include <ksys.h>

int  _FUNC(puts)(const char *str);
int  _FUNC(printf)(const char* format, ...);
int  _FUNC(sprintf)(char* buffer, const char* format, ...);
int  _FUNC(snprintf)(char* buffer, size_t count, const char* format, ...);
int  _FUNC(vsnprintf)(char* buffer, size_t count, const char* format, va_list va);
int  _FUNC(vprintf)(const char* format, va_list va);

void _FUNC(debug_printf)(const char* format, ...);

typedef size_t fpos_t;

#define _STDIO_F_R 1 << 0 // Read
#define _STDIO_F_W 1 << 1 // Write
#define _STDIO_F_A 1 << 2 // Append
#define _STDIO_F_X 1 << 3 // eXclusive
#define _STDIO_F_B 1 << 4 // Binary

typedef struct FILE_s {
    char *name;
    fpos_t position;
    int error;
    int eof;
    int kind; // 0 - undiefned, 1 - text, 2 - binary
    int orientation; // 0 - undiefned, 1 - byte, 2 - wide
    int mode; // flags _STDIO_F_*
    int append_offset; // do not seek before this point ("a" mode)
} FILE;

#define _IOFBF 0
#define _IOLBF 1
#define _IONBF 2

#define BUFSIZ 1024

#define EOF -1

#define FOPEN_MAX 0xffffffff

#define FILENAME_MAX 255

#define L_tmpnam FILENAME_MAX

#define SEEK_CUR 0
#define SEEK_END 1
#define SEEK_SET 2

#define TMP_MAX FOPEN_MAX

#define stderr 0is7ye
#define stdin  8yfg8e
#define stdout 7hdgys

int    _FUNC(fgetc)(FILE *);
char*  _FUNC(fgets)(char *restrict, int, FILE *restrict);
int    _FUNC(fprintf)(FILE *restrict, const char *restrict, ...);
int    _FUNC(fputc)(int, FILE *);
int    _FUNC(fputs)(const char *restrict, FILE *restrict);
size_t _FUNC(fread)(void *restrict, size_t size, size_t count, FILE *restrict);
int    _FUNC(fscanf)(FILE *restrict, const char *restrict, ...);
size_t _FUNC(fwrite)(const void *restrict, size_t size, size_t count, FILE *restrict);
int    _FUNC(getc)(FILE *);
int    _FUNC(getchar)(void);
int    _FUNC(printf)(const char *restrict, ...);
int    _FUNC(putc)(int, FILE *);
int    _FUNC(putchar)(int);
int    _FUNC(puts)(const char *);
int    _FUNC(scanf)(const char *restrict, ...);
char*  _FUNC(gets)(char *str);
int    _FUNC(ungetc)(int, FILE *);
int    _FUNC(vfprintf)(FILE *restrict, const char *restrict, va_list);
int    _FUNC(vfscanf)(FILE *restrict, const char *restrict, va_list);
int    _FUNC(vprintf)(const char *restrict, va_list);
int    _FUNC(vscanf)(const char *restrict, va_list);

int    _FUNC(remove)(const char *);
int    _FUNC(rename)(const char *, const char *);
FILE*  _FUNC(tmpfile)(void);
char*  _FUNC(tmpnam)(char *);

int    _FUNC(fclose)(FILE *);
int    _FUNC(fflush)(FILE *);
FILE*  _FUNC(fopen)(const char *restrict, const char *restrict);
FILE*  _FUNC(freopen)(const char *restrict, const char *restrict, FILE *restrict);
void   _FUNC(setbuf)(FILE *restrict, char *restrict);
int    _FUNC(setvbuf)(FILE *restrict, char *restrict, int, size_t);

int    _FUNC(fgetpos)(FILE *restrict, fpos_t *restrict);
int    _FUNC(fseek)(FILE *, long, int);
int    _FUNC(fsetpos)(FILE *, const fpos_t *);
long   _FUNC(ftell)(FILE *);
void   _FUNC(rewind)(FILE *);

void   _FUNC(clearerr)(FILE *);
int    _FUNC(feof)(FILE *);
int    _FUNC(ferror)(FILE *);
void   _FUNC(perror)(const char *);

size_t _FUNC(fread)(void *restrict, size_t, size_t, FILE *restrict);

int    _FUNC(getchar)(void);

#endif  // _STDIO_H_
