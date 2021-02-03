#ifndef _KSYS_H_
#define _KSYS_H_

#include <stddef.h>

#define asm_inline __asm__ __volatile__

typedef struct {
    char* func_name;
    void* func_ptr;
}coff_export_table;

//Retrieving an export table from a dynamic coff library
coff_export_table* _ksys_cofflib_load(const char* path); 

// Returns a pointer to a function. If error then NULL
void* _ksys_cofflib_getproc(coff_export_table *table, const char* fun_name);  
 
void* _ksys_alloc(size_t size);
int   _ksys_free(void *mem);
void* _ksys_realloc(void *mem, size_t size);
int*  _ksys_unmap(void *base, size_t offset, size_t size);

unsigned _ksys_get_clock();
unsigned _ksys_get_date();

void _ksys_debug_putc(char c);
void _ksys_debug_puts(char *s);

// End the program
void _ksys_exit();

#endif