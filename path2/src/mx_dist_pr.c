#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

int mx_dist_pr(int **matrix, int **recover, int p, int i) {
	int first = recover[p][i];
	int last = recover[p][i - 1];
	int sum = 0;

	while (i != 0 && recover[p][i - 1] != -1) {
		mx_printint(matrix[first][last]);
		sum = sum + matrix[first][last];
		if (i - 1 != 0 && recover[p][i - 2] != -1) {
			mx_printstr(" + ");
		} else {
			mx_printstr(" = ");
		}
		first = last;
		i--;
		last = recover[p][i - 1];
	}

return sum;
}
