#include "../inc/pathfinder.h"

void mx_print_sm(int i, int **recover, char **ostrovi, int arr) {
    mx_printstr("Route: ");
    for (int j = arr - 1; j >= 0; j--) {
        if (recover[i][j] != -1) {
            mx_printstr(ostrovi[recover[i][j]]);
            if (j != 0 && recover[i][j - 1] != -1) {
                mx_printstr(" -> ");
            }
        }
    }
    mx_printchar('\n');
}
