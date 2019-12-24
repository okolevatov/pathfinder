#include "../inc/libmx.h"

void mx_print_strarr(char **arr, const char *delim) {
	int k = 0;
	if(arr[k] && delim ) {
		while(arr[k]) {
			mx_printstr(arr[k]);
				if(arr[k + 1]) {
					mx_printstr(delim);
				}
		k++;
		}
	write(1, "\n", 1);
	}
}
