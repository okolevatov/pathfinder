#include "../libmx/inc/libmx.h"

void mx_del_intarr(int ***arr, int n) {
	int **s = *arr;

	for (int i = 0; i < n; i++) {
		free(s[i]);
	}
	free(*arr);
	*arr = NULL;
}
