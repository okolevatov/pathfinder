#include "../inc/libmx.h"

char *mx_strdup(const char *str) {
	char *buff;

	buff = mx_strnew(mx_strlen(str));
	mx_strcpy(buff, str);

	return buff;
}
