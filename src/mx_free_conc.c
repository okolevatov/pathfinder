#include "../inc/pathfinder.h"

void mx_free_conc(int ***conc) {
    int **s = *conc;

    free(s[0]);
    free(s[1]);

    free(*conc);
    *conc = NULL;
}
