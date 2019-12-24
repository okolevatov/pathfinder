#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
const char *hay = big;
const char *need = little;
size_t p = 0;
int l = 0;
size_t count = 1;

for(size_t i = 0; i < big_len; i++) {
	if(hay[i] == need[p]) {
		l = i;
		while(p < little_len) {
			if(hay[l] == need[p]) {
				p++;
				count++;
				l++;
			} else {
				break;
			}
		}
	}
	if(count == little_len) {
		return (void*) &hay[i];
	} else {
		count = 0;
		p = 0;
	}
}

return NULL;
}
