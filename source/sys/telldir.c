#include <sys/dirent.h>

unsigned telldir(DIR *dir)
{
    if(dir!=NULL){
        return dir->pos;
    }else{
        return 0;
    }
}