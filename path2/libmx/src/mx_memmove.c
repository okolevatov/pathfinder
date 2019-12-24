#include "../inc/libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
	char *s = mx_strdup(src);
	char *d = dst;

	for(size_t i = 0; i < len; i++) {
		d[i] = s[i];
	}
	free(s);
	
	return d;
}
