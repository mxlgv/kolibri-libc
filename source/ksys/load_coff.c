#include <ksys.h>
#include <string.h>

coff_export_table* _ksys_cofflib_load(const char* path)
{
    asm_inline(
        "int $0x40"
        ::"a"(68),"b"(19), "c"(path)
    );
}

void * _ksys_cofflib_getproc(coff_export_table *table, const char* fun_name)
{
    unsigned i=0;
    while (1){
        if (NULL == (table+i)->func_name){
            break;
        }else{
            if (!strcmp(fun_name, (table+i)->func_name)){
                return (table+i)->func_ptr;
            }
        }
        i++;
    }
    return NULL;
}