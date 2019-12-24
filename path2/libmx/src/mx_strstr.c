#include "../inc/libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
	int len = mx_strlen(needle);
	int j = 0;
	int i = 0;
	int try = 0;

	while(haystack[i] != '\0') {
		try = i;
		while(haystack[i] == needle[j] && needle[j] != '\0' ) {
			if(j == len - 1) {
				return (char*) &haystack[i - j];
			} 
			if(haystack[i + 1] != needle[j + 1]) {
				i = try;
				break;
			}
			j++;
			i++;
		}
		i++;
		j = 0;
	}
	return NULL;
}
