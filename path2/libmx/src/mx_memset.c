#include "../inc/libmx.h"

void *mx_memset(void *b, int c, size_t len) {
	size_t i = 0;
	char *res = b;
	while(i < len) {
		res[i] = c;
		i++;
	}

	return res;

}
