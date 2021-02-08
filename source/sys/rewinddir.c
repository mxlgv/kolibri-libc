#include <sys/dirent.h>

void rewinddir(DIR *dir){
    if(dir!=NULL){
        dir->pos=0;
    }
}