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

int  puts(const char *str);
int  printf(const char* format, ...);
int  sprintf(char* buffer, const char* format, ...);
int  snprintf(char* buffer, size_t count, const char* format, ...);
int  vsnprintf(char* buffer, size_t count, const char* format, va_list va);
int  vprintf(const char* format, va_list va);

void debug_printf(const char* format, ...);

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

int      fgetc(FILE *);
char    *fgets(char *restrict, int, FILE *restrict);
int      fprintf(FILE *restrict, const char *restrict, ...);
int      fputc(int, FILE *);
int      fputs(const char *restrict, FILE *restrict);
size_t   fread(void *restrict, size_t, size_t, FILE *restrict);
int      fscanf(FILE *restrict, const char *restrict, ...);
size_t   fwrite(const void *restrict, size_t, size_t, FILE *restrict);
int      getc(FILE *);
int      getchar(void);
int      printf(const char *restrict, ...);
int      putc(int, FILE *);
int      putchar(int);
int      puts(const char *);
int      scanf(const char *restrict, ...);
int      ungetc(int, FILE *);
int      vfprintf(FILE *restrict, const char *restrict, va_list);
int      vfscanf(FILE *restrict, const char *restrict, va_list);
int      vprintf(const char *restrict, va_list);
int      vscanf(const char *restrict, va_list);

int      remove(const char *);
int      rename(const char *, const char *);
FILE    *tmpfile(void);
char    *tmpnam(char *);

int      fclose(FILE *);
int      fflush(FILE *);
FILE    *fopen(const char *restrict, const char *restrict);
FILE    *freopen(const char *restrict, const char *restrict, FILE *restrict);
void     setbuf(FILE *restrict, char *restrict);
int      setvbuf(FILE *restrict, char *restrict, int, size_t);

int      fgetpos(FILE *restrict, fpos_t *restrict);
int      fseek(FILE *, long, int);
int      fsetpos(FILE *, const fpos_t *);
long     ftell(FILE *);
void     rewind(FILE *);

void     clearerr(FILE *);
int      feof(FILE *);
int      ferror(FILE *);

#endif  // _STDIO_H_
