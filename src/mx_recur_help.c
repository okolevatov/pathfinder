#include "../inc/pathfinder.h"

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

static int *copi(int *bwsvk_eik) {
    int *bwsvk_eik2 = (int*)(malloc)(sizeof(int) * (12));

    for (int i = 0; i < 12; i++) {
        bwsvk_eik2[i] = bwsvk_eik[i];
    }
    return bwsvk_eik2;
}

static int **copmatr(int **matrix, int kilkist) {
    int **arr = (int **) malloc (sizeof (int *) * (kilkist));

    for (int q = 0; q < kilkist; q++) {
        arr[q] = (int*)(malloc)(sizeof(int) * (kilkist));
        for (int j = 0; j < kilkist; j++) {
            arr[q][j] = matrix[q][j];
        }
    }   
    return arr;
}

static int helper(int *bwsvk_eik1, int **buffarr, int **copymatr, int *dest) {
    bwsvk_eik1[0] = bwsvk_eik1[1] - copymatr[bwsvk_eik1[5]][bwsvk_eik1[3]]; 
    if (dest[bwsvk_eik1[3]] == bwsvk_eik1[0]) {
    copymatr[bwsvk_eik1[5]][bwsvk_eik1[3]] = MI;
        bwsvk_eik1[8] = mx_rewrite(bwsvk_eik1, buffarr, bwsvk_eik1[6]);
        bwsvk_eik1[11] = mx_recur_help(copymatr, dest, bwsvk_eik1, buffarr);
        bwsvk_eik1[1] = bwsvk_eik1[0];
        bwsvk_eik1[5] = bwsvk_eik1[3];
        buffarr[bwsvk_eik1[6]][bwsvk_eik1[9]] = bwsvk_eik1[3]; 
        bwsvk_eik1[9]++;
        bwsvk_eik1[2] = same_path(copymatr, dest, bwsvk_eik1);
    }
    return bwsvk_eik1[9];
}

int mx_recur_help(int **matrix, int *dest, int *bwsvk_eik, int **buffarr) {
    int *b1 = copi(bwsvk_eik);
    int **cm = copmatr(matrix, bwsvk_eik[7]);
    int k_s[2] = {b1[8], 0};

    k_s[1] = mx_rec_1(b1, cm, dest, k_s[1]);
    while (b1[10] != b1[5]) { 
        for (int i = 0; i < bwsvk_eik[7]; i++) {
            if (cm[b1[5]][i] != 0 && cm[b1[5]][i] != MI && (b1[2] <= 1)) {
                mx_rh_1(b1, i, k_s[1], cm);
                k_s[0] = mx_recur_help1(b1, buffarr, k_s[0], dest);
                b1[2] = same_path(cm, dest, b1);
            } else if (cm[b1[5]][i] != 0 && cm[b1[5]][i] != MI && b1[2] > 1) {
                mx_rh_2(b1, i, k_s[1], k_s[0]);
                k_s[0] = helper(b1, buffarr, cm, dest);
                b1[2] = same_path(cm, dest, b1);
            }
        }
    }
    k_s[1] = mx_del_cmatr1(b1, cm);
    return k_s[1];
}
