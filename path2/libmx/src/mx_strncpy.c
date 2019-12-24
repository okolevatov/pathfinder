#include "../inc/libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
	int i = 0;
	int j;

	while(src && i < len) {
		dst[i] = src[i];
		i++;
	}
	j = i;
	if(src[i] == '\0') {
		while(j < len) {
			dst[j] = '\0';
		}
	}
	return dst;
}
