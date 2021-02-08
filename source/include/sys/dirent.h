#ifndef _DIRENT_H_
#define _DIRENT_H_

#include <stddef.h>
#include <limits.h>

#define IS_FOLDER 16
#define IS_FILE 0

typedef unsigned ino_t;

struct dirent{
   ino_t    d_ino;   //File serial number. 
   char     d_name[PATH_MAX];   // Name of entry. 
   unsigned d_type;
};

typedef struct{
    struct dirent* objs; 
    ino_t pos;
    ino_t num_objs;   
}DIR;


int closedir(DIR *dir);
DIR *opendir(const char *path);
struct dirent *readdir(DIR *);
void rewinddir(DIR *dir);
void seekdir(DIR *dir, unsigned pos);
unsigned telldir(DIR *dir);

#endif // _DIRENT_H_