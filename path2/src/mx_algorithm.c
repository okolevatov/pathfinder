#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

static int kilkistt (char *str1) {
	char *str = mx_file_to_str(str1);
	int i = 0;
	int j = 0;
	int kilkisto;
	char *number = NULL;

	while (str[i] != '\n') {
		i++;
	}
	number = mx_strnew(i);
	while (str[j] != '\n') {
		number[j] = str[j];
		j++;
	}
	kilkisto = mx_atoi(number);
	mx_strdel(&number);
	mx_strdel(&str);
	return kilkisto;
}

static int min_index (int *dest, int kilkist, int *vis) {
	int min;

	min = mx_min_number(dest, kilkist, vis);
	for (int i = 0; i < kilkist; i++) {
		if (min == dest[i]) {
			return i;
		}
	}
	return 0;
}

static int *algorithm1 (int *dest, int *vis, int **matrix, int *kb) { 
	int min_mindex[3] = {0, 0, 0}; 
	
	for (int i = 0; i < kb[0]; i++) { 
		for (int j = 0; j < kb[0]; j++) { 
			if (i == 0) {
				dest[j] = matrix[kb[1]][j]; 
				vis[kb[1]] = 1; 
			} else {
				min_mindex[2] = j;
				dest = mx_algorithm_helper(min_mindex, vis, matrix, dest);
				if (j + 1 == kb[0]) 
					vis[min_mindex[1]] = 1;
			}
		}
		min_mindex[1] = min_index(dest, kb[0], vis); 
		min_mindex[0] = mx_min_number(dest, kb[0], vis); 
	}
	return dest;
}

static int *create (int **matrix, int kilkist, int st) { 
	int *dest = (int*)(malloc)(sizeof(int) * (kilkist));
	int *vis = (int*)(malloc)(sizeof(int) * (kilkist));
	int kb[2] = {kilkist, st};
	
	for (int i = 0; i < kilkist; i++) {
    	dest[i] = 2147483647;
    	vis[i] = 0;
  	}
  	dest[kb[1]] = 0; 
  	dest = algorithm1(dest, vis, matrix, kb); 
  	free(vis);
 	return dest;
}

void mx_algorithm (int **matrix, char *str, char **ostrovi) {
	int kilkist = kilkistt(str);
	int *alcopy = NULL;
	int **recover = NULL;
	int arr[3] = {kilkist, 0, 0};
	int **conc1 = NULL;

	for (; arr[2] < kilkist - 1; arr[2]++) {
		alcopy = create(matrix, kilkist, arr[2]); 
		recover = mx_recovery_alg(kilkist, alcopy, arr[2], matrix);
		arr[1] = arr[2];
		conc1 = mx_creating_arr(arr, alcopy, kilkist);
		mx_print_route(ostrovi, matrix, recover, conc1);
		mx_free_conc(&conc1);
		free(alcopy);
		mx_del_intarr(&recover, kilkist);
	}
}

