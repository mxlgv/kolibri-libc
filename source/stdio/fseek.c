#include <stdio.h>
#include <ksys.h>

int fseek(FILE *stream, long int offset, int whence) {
	if (whence == SEEK_SET) {
		stream->position = offset;
	} else if (whence == SEEK_CUR) {
		stream->position += offset;
	} else if (whence == SEEK_END) {
		BDFE_struct info;
	    if (_ksys_file_get_info(stream->name, &info)) {
	        return -1;
	    }
	    stream->position = info.size + offset;
	}
	stream->eof = 0;
}
