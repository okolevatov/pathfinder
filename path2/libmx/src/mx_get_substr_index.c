#include "../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
	int result = 0;
	int j = 0;

	if(str == NULL || sub == NULL) {
		return -2;
	}

	if(mx_strstr(str, sub) == NULL) {
		return -1;
	}

	int strlen = mx_strlen(str);
	int sublen = mx_strlen(sub);
	for(int i = 0; i < strlen; i++) {
		while(str[i] == sub[j]) {
			if(str[i] != sub[j]) {
				j = 0;
			}
			j++;
		}
		if(j == sublen) {
			return result = i - sublen + 1;
		}
	}
	
	return result;
}

