#include "../inc/pathfinder.h"

int mx_test_same(int *dest, int **matr, int end, int kilkist) { 
    int buff;
    int weight = dest[end];
    int newend = 0;
    int same = 0;

    for (int i = 0; i < kilkist; i++) {
        if (matr[end][i] != 0 && matr[end][i] != 2147483647) {
            buff = weight - matr[end][i];
            if (dest[i] == buff) { 
                newend = i;
                same++;
            }
        }
    } 
    if (same == 1) {
        same = mx_test_same(dest, matr, newend, kilkist);
    }
    return same;
}
