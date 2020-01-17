static int same_path(int **matrix, int *dest, int *bwsvk_eik) {
    int buff = 0;
    int weight = dest[bwsvk_eik[5]];
    int same = 0;
    int max = 2147483647;

    for (int i = 0; i < bwsvk_eik[7]; i++) {
        if (matrix[bwsvk_eik[5]][i] != 0 && matrix[bwsvk_eik[5]][i] != max) { 
            buff = weight - matrix[bwsvk_eik[5]][i];
            if (dest[i] == buff) {
                same++;
            }
        }
    }
    return same;
}

int mx_rec_1(int *bwsvk_eik1, int **cm, int *dest, int k_s) {
	bwsvk_eik1[11] = bwsvk_eik1[11] + 1;
    bwsvk_eik1[2] = same_path(cm, dest, bwsvk_eik1);
    k_s = bwsvk_eik1[11];
    return k_s;
}
