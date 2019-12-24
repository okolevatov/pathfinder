#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

int mx_dist_pr_same(int **matrix, int *recover, int i) {
	int first = recover[i];
	int last = recover[i - 1];
	int sum = 0;

	while (i != 0 && recover[i - 1] != -1) {
		mx_printint(matrix[first][last]);
		sum = sum + matrix[first][last];
		if(i - 1 != 0 && recover[i - 2] != -1) {
			mx_printstr(" + ");
		} else {
			mx_printstr(" = ");
		}
		first = last;
		i--;
		last = recover[i - 1];
	}
	return sum;
}
