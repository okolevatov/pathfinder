#include "../inc/pathfinder.h"

static int number(int **new, int kilkist) {
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

static void sort(int **new, int kilkist, int i) {
    int *buff = (int*)(malloc)(sizeof(int) * (kilkist));
    int a = 0;
    int j = 0;

    for (a = 0; a < kilkist; a++) {
        buff[a] = -1;
    }
    for (j = 0; j < kilkist; j++) {
        buff[j] = new[i + 1][j];
    }
    for (a = 0; a < kilkist; a++) {
        new[i + 1][a] = new[i][a];
    }
    for (j = 0; j < kilkist; j++) {
        new[i][j] = buff[j];
    }
    free(buff);
    buff = NULL;
}

static int wh_il(int **new, int i, int j) {
    while (new[i][j] == -1) {
        j--;
    }
    return j;
}

void mx_sort_arr(int **new, int kilkist) {
    int num = number(new, kilkist);
    int k = kilkist - 1;

    for (int q = 0; q < num; q++) {
        for (int i = 0; i < num - 1; i++) {
            for (int j = kilkist - 1; j >= 0 && k >= 0; j--, k--) {
                j = wh_il(new, i, j);
                k = wh_il(new, i + 1, k);
                if (new[i + 1][k] < new[i][j]) {
                    sort(new, kilkist, i);
                    k = kilkist - 1;
                    break;
                } else if (new[i][j] < new[i + 1][k]) {
                    k = kilkist - 1;
                    break;
                }
            }
        }
    }
}
