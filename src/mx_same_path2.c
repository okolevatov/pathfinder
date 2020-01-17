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

static int **create(int kil_b) {
    int **buffarr1 = NULL;

    buffarr1 = (int **) malloc (sizeof (int *) * (1000)); 
    for (int h = 0; h < 1000; h++) {
        buffarr1[h] = (int*)(malloc)(sizeof(int) * (kil_b));
        for (int i = 0; i < kil_b; i++) {
            buffarr1[h][i] = -1;
        }
    }
    return buffarr1;
}

static void check0(int *b_w_s_v_k, int **buffarr, int **matrix, int *dest) {
    buffarr[b_w_s_v_k[11]][b_w_s_v_k[4]] = b_w_s_v_k[5];
    b_w_s_v_k[4]++;
    b_w_s_v_k[2] = same_path(matrix, dest, b_w_s_v_k);
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

int **mx_same_path2(int **ma, int end, int *dest, int *kil_b) {
    int **buffarr = create(kil_b[0]);
    int b[12] = {0, dest[end], 0, 0, 0, end, 0, kil_b[0], 0, 1, kil_b[1], 0};
    int **copymatr = copmatr(ma, kil_b[0]);

    check0(b, buffarr, ma, dest);
    while (kil_b[1] != b[5]) {
        for (int i = 0; i < b[7]; i++) {
            if (ma[b[5]][i] != 0 && ma[b[5]][i] != MI && (b[2] <= 1)) {
                b[3] = i;
                mx_sp_h2(dest, b, buffarr, ma);
            } else if (ma[b[5]][i] != 0 && ma[b[5]][i] != MI && (b[2] > 1)) {
                b[3] = i;
                mx_sp_helper(dest, b, copymatr, buffarr);
                b[2] = same_path(ma, dest, b);
            }
        }
    }
    mx_del_cmatr(b[7], copymatr);
    return buffarr;
}
