#include "../inc/libmx.h"

char *mx_strndup(const char *s1, size_t n) {
	char *buff = NULL;
	
	size_t d = mx_strlen(s1);
	if(d < n) {
		buff = mx_strnew(d);
		mx_strcpy(buff, s1);
	} else if(n <= d) {
		buff = mx_strnew(n);
		for(size_t i = 0; i < n; i++){
			buff[i] = s1[i];
		}
	}
	
	return buff;
}
