#include "../inc/libmx.h"

int mx_count_substr(const char *str, const char *sub) {
	int count = 0;
	int end = mx_strlen(sub);
	int q = 0;
	
	if(str == NULL || sub == NULL) {
		return -1;
	}
	for(int i = 0; i < mx_strlen(str); i++) {
		q = i;
		if(str[i] == sub[0]) {
			for(int j = 0; j < end; j++) {
				if(str[q] != sub[j]) {
					break;
				} else if(str[q] == sub[j]) {
					if(j + 1 == end) {
						count++;
						break;
					}
					q++;
				} 
			}
		}
	}

	return count;
}
