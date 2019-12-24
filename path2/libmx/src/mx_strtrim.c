#include "../inc/libmx.h"

char *mx_strtrim(const char *str) {
	int size = mx_strlen(str);
	int j = 0;
	int k = size - 1;
	int len = 0;

	if(str == NULL) {
		return NULL;
	}

	while((str[j] >= 9 && str[j] <= 13) || str[j] == 32 || str[j] == 82) {
		j++;
	}
	while((str[k] >= 9 && str[k] <= 13) || str[k] == 32 || str[k] == 82) {
		k--;
	}
	len = k - j + 1;

	char *buff = mx_strnew(len);

	for(int i = 0; i < len ; i++) {
		buff[i] = str[j];
		j++;
	}
	
	return buff;

}
