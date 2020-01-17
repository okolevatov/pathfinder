#include "../inc/pathfinder.h"

int mx_cof_same(int **new, int kilkist) {
    int p = 0;
    int i = 0;
    int j = 0;

    while (new[i][j] != -2) {
        for (; j < kilkist; j++) {
            if (new[i][j] == -1) {
                p++;
            }
            if (p == kilkist) {
                return i; 
            }
        }
        p = 0;
        i++;
        j = 0;
    }
    return i;
}
