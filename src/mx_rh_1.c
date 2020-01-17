void mx_rh_1(int *bwsvk_eik1, int i, int stream, int **copymatr) {
    bwsvk_eik1[3] = i;
    bwsvk_eik1[6] = stream;
    bwsvk_eik1[0] = bwsvk_eik1[1] - copymatr[bwsvk_eik1[5]][i];
}
