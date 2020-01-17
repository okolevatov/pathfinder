#include "../inc/pathfinder.h"

void mx_conc1_del(int ***conc) {
    int **j = *conc;

    for (int i = 0; i < 2; i++) {
        free(j[i]);
    }
    free(*conc);
    *conc = NULL;
}
