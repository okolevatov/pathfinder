#include "../inc/pathfinder.h"

void mx_free_rout(int **new, int *sf_same, int kilkist) {
	kilkist = 1000;
    for (int i = 0; i < kilkist; i++) {
        free(new[i]);
    }
    free(new);
    new = NULL;
    free(sf_same);
    sf_same = NULL;
}
