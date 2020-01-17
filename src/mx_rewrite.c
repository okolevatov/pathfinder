#include "../inc/pathfinder.h"

int mx_rewrite(int *bwsvk_eik, int **buffarr, int stream) {
    int k = bwsvk_eik[11] + 1;
    int i = 0;

    while (buffarr[stream][i] != -1) { 
        buffarr[k][i] = buffarr[stream][i];
        i++;
    }
    return i;
}
