#include <stdio.h>

size_t fread(void *restrict ptr, size_t size, size_t nmemb, FILE *restrict stream) {
	unsigned bytes_read = 0;
	unsigned bytes_count = size * nmemb;
	_ksys_file_read_file(stream->name, stream->position, bytes_count, ptr, &bytes_read);
	stream->position += bytes_read;
	return bytes_read / size;
}
