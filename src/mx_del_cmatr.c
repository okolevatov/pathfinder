#include "../inc/pathfinder.h"

void mx_del_cmatr(int kilkist, int **copymatr) {
    for (int y = 0; y < kilkist; y++) {
        free(copymatr[y]);
    }
    free(copymatr);
    copymatr = NULL;
}
