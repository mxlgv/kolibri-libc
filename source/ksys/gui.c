#include <ksys.h>

void _ksys_begin_draw()
{
   asm_inline("int $0x40"::"a"(12),"b"(1));
}

void _ksys_end_draw()
{
    asm_inline("int $0x40" ::"a"(12),"b"(2));
}

void _ksys_create_window(int x, int y, int w, int h, const char *name, unsigned workcolor, unsigned style)
{
    asm_inline(
        "int $0x40"
        ::"a"(0),
        "b"((x << 16) | ((w-1) & 0xFFFF)),
        "c"((y << 16) | ((h-1) & 0xFFFF)),
        "d"((style << 24) | (workcolor & 0xFFFFFF)),
        "D"(name),
        "S"(0) : "memory"
     );
};

void _ksys_change_window(int new_x, int new_y, int new_w, int new_h)
{
    asm_inline(
        "int $0x40"
        ::"a"(67), "b"(new_x), "c"(new_y), "d"(new_w),"S"(new_h)
    );
}
 
void _ksys_define_button(unsigned x, unsigned y, unsigned w, unsigned h, unsigned id, unsigned color)
{
   asm_inline(
        "int $0x40"
        ::"a"(8),
        "b"((x<<16)+w),
        "c"((y<<16)+h),
        "d"(id),
        "S"(color)
    );
};

void _ksys_draw_line(int xs, int ys, int xe, int ye, unsigned color)
{
    asm_inline(
        "int $0x40"
        ::"a"(38), "d"(color),
        "b"((xs << 16) | xe),
        "c"((ys << 16) | ye)
    );
}

void _ksys_draw_bar(int x, int y, int w, int h, unsigned color)
{
    asm_inline(
        "int $0x40"
        ::"a"(13), "d"(color),
        "b"((x << 16) | w),
        "c"((y << 16) | h)
    );
}
 
void _ksys_draw_bitmap(void *bitmap, int x, int y, int w, int h)
{
    asm_inline(
        "int $0x40"
        ::"a"(7), "b"(bitmap),
        "c"((w << 16) | h),
        "d"((x << 16) | y)
    );
}

void _ksys_draw_text(const char *text, int x, int y, int len, unsigned color)
{
   asm_inline(
        "int $0x40"
        ::"a"(4),"d"(text),
        "b"((x << 16) | y),
        "S"(len),"c"(color)
        :"memory"
    );
}

void _ksys_draw_text_bg(const char *text, int x, int y, int len, unsigned color, unsigned bg)
{
    asm_inline(
        "int $0x40"
        ::"a"(4),"d"(text),
        "b"((x << 16) | y),
        "S"(len),"c"(color), "D"(bg)
        :"memory"
    );
}