#include "../inc/pathfinder.h"

void mx_sp_helper(int *dest, int *bwsvk_eik, int **copymatr, int **buffarr) {
	bwsvk_eik[0] = bwsvk_eik[1] - copymatr[bwsvk_eik[5]][bwsvk_eik[3]];
    if (dest[bwsvk_eik[3]] == bwsvk_eik[0]) {
        copymatr[bwsvk_eik[5]][bwsvk_eik[3]] = 2147483647;
        bwsvk_eik[8] = mx_rewrite(bwsvk_eik, buffarr, 0);
        bwsvk_eik[11] = mx_recur_help(copymatr, dest, bwsvk_eik, buffarr);
        bwsvk_eik[1] = bwsvk_eik[0];
        bwsvk_eik[5] = bwsvk_eik[3];
        buffarr[0][bwsvk_eik[4]] = bwsvk_eik[3]; 
        bwsvk_eik[4]++;
    }
}
