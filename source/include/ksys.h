#ifndef _KSYS_H_
#define _KSYS_H_

#define asm_inline __asm__ __volatile__

typedef struct {
    char* func_name;
    void* func_ptr;
}coff_export_table;

void _ksys_begin_draw();
void _ksys_end_draw();
void _ksys_create_window(int x, int y, int w, int h, const char *name, unsigned workcolor, unsigned style);
void _ksys_change_window(int new_x, int new_y, int new_w, int new_h);
void _ksys_define_button(unsigned x, unsigned y, unsigned w, unsigned h, unsigned id, unsigned color);
void _ksys_draw_line(int xs, int ys, int xe, int ye, unsigned color);
void _ksys_draw_bar(int x, int y, int w, int h, unsigned color);
void _ksys_draw_bitmap(void *bitmap, int x, int y, int w, int h);
void _ksys_draw_text(const char *text, int x, int y, int len, unsigned color);
void _ksys_draw_text_bg(const char *text, int x, int y, int len, unsigned color, unsigned bg);

//Retrieving an export table from a dynamic coff library
coff_export_table* _ksys_cofflib_load(const char* path); 

// Returns a pointer to a function. If error then NULL
void* _ksys_cofflib_getproc(coff_export_table *table, const char* fun_name);  
 
// End the program
void _ksys_exit();

#endif