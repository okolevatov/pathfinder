#include "../inc/pathfinder.h"

int mx_del_cmatr1(int *bwsvk_eik1, int **copymatr) {
    int k = 0;

    for (int y = 0; y < bwsvk_eik1[7]; y++) {
        free(copymatr[y]);
    }
    k = bwsvk_eik1[11];
    free(copymatr);
    copymatr = NULL;
    free(bwsvk_eik1);
    return k;
}
