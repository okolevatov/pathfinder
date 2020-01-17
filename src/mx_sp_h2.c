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


void mx_sp_h2(int *dest, int *bwsvk_eik, int **buffarr, int **matrix) {
    bwsvk_eik[0] = bwsvk_eik[1] - matrix[bwsvk_eik[5]][bwsvk_eik[3]];
    if (dest[bwsvk_eik[3]] == bwsvk_eik[0]) {
        bwsvk_eik[1] = bwsvk_eik[0];
        bwsvk_eik[5] = bwsvk_eik[3];
        buffarr[0][bwsvk_eik[4]] = bwsvk_eik[3]; 
        bwsvk_eik[4]++;
        bwsvk_eik[2] = same_path(matrix, dest, bwsvk_eik);
    }
}
