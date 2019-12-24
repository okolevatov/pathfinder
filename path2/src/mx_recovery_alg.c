#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

static int **rec_matrix(int kilkist) {
	int **arr = NULL;

	arr = (int **) malloc (sizeof (int *) * (kilkist));
	for (int q = 0; q < kilkist; q++) {
		arr[q] = (int*)(malloc)(sizeof(int) * (kilkist));
		for (int j = 0; j < kilkist; j++) {
			arr[q][j] = -1;
		}
	}
	return arr;
}

static int check1(int **matrix, int end, int i, int weight) {
	int buff = 0;

	if (matrix[end][i] != 0 && matrix[end][i] != 2147483647) {
     	buff = weight - matrix[end][i]; 
     	return buff;
    }
	return -1;
}

static void check2(int *en_b_w_k_b, int i, int j, int **ver) {
	en_b_w_k_b[2] = en_b_w_k_b[1];
    en_b_w_k_b[0] = i;
    ver[j][en_b_w_k_b[3]] = i; 
    en_b_w_k_b[3]++;
}

static void check3(int *en_b_w_k_b, int *dest) {
	en_b_w_k_b[4]++;
  	en_b_w_k_b[0] = en_b_w_k_b[4];
  	en_b_w_k_b[2] = dest[en_b_w_k_b[0]];
  	en_b_w_k_b[3] = 1; 
}

int **mx_recovery_alg(int kilkist, int *dest, int begin, int **matrix) { 
	int **ver = NULL;
	int en_b_w_k_b[6] = {1, 0, dest[1], 1, 1, 0};	

	ver = rec_matrix(kilkist);
	for (int j = 1; j < kilkist; j++) {
		ver[j][0] = en_b_w_k_b[0];  
		while (en_b_w_k_b[0] != begin) {
			for (int i = 0; i < kilkist; i++) { 
				if ((en_b_w_k_b[1] = check1(matrix, en_b_w_k_b[0], i, en_b_w_k_b[2]))!= -1) {
     				if (dest[i] == en_b_w_k_b[1]) { 
     					check2(en_b_w_k_b, i, j, ver);
     				}
    			}
  			}
  			mx_ne_svyz(en_b_w_k_b);
  		}
  		check3(en_b_w_k_b, dest);
 	}
  	return ver;
}

