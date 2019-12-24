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

static int check1(int *bwsvk_eik, int end, int i, int *buffarr) {
	bwsvk_eik[1] = bwsvk_eik[0];
    end = i;
    buffarr[bwsvk_eik[4]] = end;
    bwsvk_eik[4]++;
    return end;
}

int mx_hpath(int *dest, int *bwsvk_eik, int *buffarr, int **matrix) {
	if (dest[bwsvk_eik[6]] == bwsvk_eik[0]) {
		if (bwsvk_eik[2] >= 2) {
      		if (bwsvk_eik[3] == 0) {
				bwsvk_eik[3]++;
			} else if (bwsvk_eik[3] >= 1){
				bwsvk_eik[5] = check1(bwsvk_eik, bwsvk_eik[5], bwsvk_eik[6], buffarr);
      			bwsvk_eik[2] = same_path(matrix, bwsvk_eik[5], dest, bwsvk_eik[7]);
			}
			return bwsvk_eik[5];
      	}
      	bwsvk_eik[5] = check1(bwsvk_eik, bwsvk_eik[5], bwsvk_eik[6], buffarr);
      	bwsvk_eik[2] = same_path(matrix, bwsvk_eik[5], dest, bwsvk_eik[7]);
	}
	return bwsvk_eik[5];
}
