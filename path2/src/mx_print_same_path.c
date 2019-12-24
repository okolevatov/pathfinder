#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

static int *fprint_path(int kilkist, int *recover) {
	int *sf = (int*)(malloc)(sizeof(int) * (2));
	int flag = 0;

	for (int j = kilkist - 1; j >= 0; j--) {
		if(recover[j] != -1) {
			flag = 1;
		}
		if (flag == 1) {
			sf[0] = recover[j];
			while (j != 0 && recover[j - 1] != -1) {
				j--;
			}
			sf[1] = recover[j];
			break;
		}
	}
	return sf;
}


static int counter_ostr(int *recover, int kilkist) {
	int count = 0;

	for (int i = kilkist - 1; i >= 0; i--) {
		if (recover[i] != -1) {
			count++;
		}
	}
	return count;
}

static void print_dist(int **matrix, int *recover, int kilkist) {
	int sum;
	int flag = 0;

	mx_printstr("Distance: ");
	for (int i = kilkist - 1; i >= 0; i--) {
		if (counter_ostr(recover, kilkist) == 2) {
			if (recover[i] != -1 && flag == 0) {
				mx_printint(matrix[recover[i]][recover[i - 1]]);
				flag++;
			}
		} else {
			if (recover[i] != -1) {
				sum = mx_dist_pr_same(matrix, recover, i);
				mx_printint(sum);
				break;
			}
		}
	}
}

static void print_path(char **ostrovi, int kilkist, int *recover) {
	int *sf = fprint_path(kilkist, recover);

	mx_printstr("Path: ");
	for (int i = 0; i < 2; i++) {
		mx_printstr(ostrovi[sf[i]]);
		if (i != 1) {
			mx_printstr(" -> ");
		}
	}
	mx_printchar('\n');
	free(sf);
}

void mx_print_same_path(char **ostrovi, int **matrix, int *arr, int *recover) {
	mx_printstr("========================================\n");
	print_path(ostrovi, arr[0], recover);
	mx_printstr("Route: ");
	for (int j = arr[0] - 1; j >= 0; j--) {
		if (recover[j] != -1) {
			mx_printstr(ostrovi[recover[j]]);
			if (j != 0 && recover[j - 1] != -1) {
				mx_printstr(" -> ");
			}
		}
	}
	mx_printchar('\n');
	print_dist(matrix, recover, arr[0]);
	mx_printchar('\n');
	mx_printstr("========================================\n");
}






