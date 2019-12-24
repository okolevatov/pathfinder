#include "../inc/libmx.h"

int mx_count_words(const char *str, char c) {
	int count = 0;
	int count_s = 0;

	if(str == NULL) {
		return -1;
	}
	for(int i = 0; i < mx_strlen(str); i++) {
		if(str[i] == c) {
			count_s = 0;
		} else if(count_s == 0) {
			count++;
			count_s = 1;
		}

	}
	return count;
}
