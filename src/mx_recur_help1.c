#include "../inc/pathfinder.h"

int mx_recur_help1(int *bwsvk_eik1, int **buffarr, int k, int *dest) {
    if (dest[bwsvk_eik1[3]] == bwsvk_eik1[0]) {
        bwsvk_eik1[1] = bwsvk_eik1[0];
        bwsvk_eik1[5] = bwsvk_eik1[3];
        buffarr[bwsvk_eik1[6]][k] = bwsvk_eik1[3]; 
        k++;
    }
    return k;
}
