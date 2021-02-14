#include <stdio.h>

FILE *fopen(const char *restrict name, const char *restrict mode) {
    FILE *out = malloc(sizeof(FILE));

    if (!out) {
        return NULL;
    }

    out->name = name;
    out->position = 0;
    out->error = 0;
    out->eof = 0;
    out->kind = 0;
    out->orientation = 0;
    out->mode = 0;

    if (strchr(mode, 'b')) { mode |= _STDIO_F_B; }
    if (strchr(mode, 'x')) { mode |= _STDIO_F_X; }
    if (strchr(mode, 'a')) { mode |= _STDIO_F_A; }
    if (strchr(mode, 'r')) { mode |= _STDIO_F_R; }
    if (strchr(mode, 'w')) { mode |= _STDIO_F_W; }
    if (strchr(mode, '+')) { mode |= _STDIO_F_R | _STDIO_F_W; }

    if (mode |= _STDIO_F_A) {
        BDFE_struct info;
        if (_ksys_file_get_info(out->name, &info)) {
            return NULL;
        }
        out->position = info.size;
        out->append_offset = info.size;
    }

    return out;
}
