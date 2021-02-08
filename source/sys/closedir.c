#include <sys/dirent.h>
#include <stdlib.h>

int closedir(DIR *dir){
    if(dir == NULL){
        return -1;
    }else{
        free(dir->objs);
        free(dir);
        return 0;
    }
}