#include "../inc/libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
	char *a = dst;
	const char *b = src;

	for(size_t i = 0; i < n; i++) {
		a[i] = b[i];
	}

	return a;
}

