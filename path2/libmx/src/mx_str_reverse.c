#include "../inc/libmx.h"

void mx_str_reverse(char *s) {
	int k = mx_strlen(s);
	int j = k;

	for(int i = 0; i < k / 2; i++) {
		mx_swap_char(&s[i], &s[j - 1]);
		j--;
	}
}
