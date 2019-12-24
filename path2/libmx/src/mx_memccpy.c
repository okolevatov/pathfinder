 #include "../inc/libmx.h"

 void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
 	char *d = dst;
 	const char *s = src;
 	size_t i = 0;

 	while(i < n) {
 		if(s[i] == c) {
 			break;
 		}
 		d[i] = s[i];
 		i++;
 	}
 	return d;
 }

 
