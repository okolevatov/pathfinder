#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

static int same_path(int **matrix, int end, int *dest, int kilkist) {
	int buff = 0;
	int weight = dest[end];
	int same = 0;

	for (int i = 0; i < kilkist; i++) {
		if (matrix[end][i] != 0 && matrix[end][i] != 2147483647) { 
			buff = weight - matrix[end][i];
			if (dest[i] == buff) {
				same++;
			}
		}
	}
	return same;
}

static int *create(int kil_b) {
	int *buffarr1 = NULL;

	buffarr1 = (int*)(malloc)(sizeof(int) * (kil_b)); 
	for (int h = 0; h < kil_b; h++) {
		buffarr1[h] = -1;
	}
	return buffarr1;
}

static void check0(int *b_w_s_v_k, int end, int *buffarr) {
	buffarr[b_w_s_v_k[4]] = end;
	b_w_s_v_k[4]++;
}

int *mx_same_path2(int **matrix, int end, int *dest, int *kil_b) {
	int *buffarr = create(kil_b[0]);
	int bwsvk_eik[8] = {0, dest[end], 0, 0, 0, 0, 0, 0};
	
	bwsvk_eik[2] = same_path(matrix, end, dest, kil_b[0]);
	check0(bwsvk_eik, end, buffarr);
	while (kil_b[1] != end) {
		bwsvk_eik[3] = 0;
		for (int i = 0; i < kil_b[0]; i++) {
			if (matrix[end][i] != 0 && matrix[end][i] != 2147483647) { 
				bwsvk_eik[0] =  bwsvk_eik[1] - matrix[end][i];
				bwsvk_eik[5] = end;
				bwsvk_eik[6] = i;
				bwsvk_eik[7] = kil_b[0];
				end = mx_hpath(dest, bwsvk_eik, buffarr, matrix);
			}
		}
	}
	return buffarr;
}
