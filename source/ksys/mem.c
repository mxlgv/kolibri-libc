#include <ksys.h>
#include <stddef.h>

void* _ksys_alloc(size_t size){
    void  *val;
    asm_inline(
        "int $0x40"
        :"=a"(val)
        :"a"(68),"b"(12),"c"(size)
    );
    return val;
}
 
int _ksys_free(void *mem)
{
    int  val;
    asm_inline(
        "int $0x40"
        :"=a"(val)
        :"a"(68),"b"(13),"c"(mem)
    );
    return val;
}

void* _ksys_realloc(void *mem, size_t size)
{
    void *val;
    asm_inline(
        "int $0x40"
        :"=a"(val)
        :"a"(68),"b"(20),"c"(size),"d"(mem)
        :"memory"
    );
    return val;
};
 

int *_ksys_unmap(void *base, size_t offset, size_t size)
{
    int  *val;
    asm_inline(
        "int $0x40"
        :"=a"(val)
        :"a"(68),"b"(26),"c"(base),"d"(offset),"S"(size)
    );
    return val;
};