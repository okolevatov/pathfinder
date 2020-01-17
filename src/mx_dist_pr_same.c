#include "../inc/pathfinder.h"

int mx_dist_pr_same(int **matrix, int **recover, int i, int j) {
    int first = recover[j][i];
    int last = recover[j][i - 1];
    int sum = 0;

    while (i != 0 && recover[j][i - 1] != -1) {
        mx_printint(matrix[first][last]);
        sum = sum + matrix[first][last];
        if(i - 1 != 0 && recover[j][i - 2] != -1) {
            mx_printstr(" + ");
        } else {
            mx_printstr(" = ");
        }
        first = last;
        i--;
        last = recover[j][i - 1];
    }
    return sum;
}
