#include "../inc/libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
const char *str = s;


	for(size_t i = n - 1; i > 0; i--) {
		if(str[i] == c) {
			return (void*) &str[i];
		}
	}
	
return NULL;
}
