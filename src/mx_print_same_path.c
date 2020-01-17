#include "../inc/pathfinder.h"

static int *fprint_path(int kilkist, int **recover) {
    int *sf = (int*)(malloc)(sizeof(int) * (2));
    int flag = 0;

    for (int j = kilkist - 1; j >= 0; j--) {
        if(recover[0][j] != -1) {
            flag = 1;
        }
        if (flag == 1) {
            sf[0] = recover[0][j];
            while (j != 0 && recover[0][j - 1] != -1) {
                j--;
            }
            sf[1] = recover[0][j];
            break;
        }
    }
    return sf;
}


static int counter_ostr(int **recover, int kilkist, int j) {
    int count = 0;

    for (int i = kilkist - 1; i >= 0; i--) {
        if (recover[j][i] != -1) {
            count++;
        }
    }
    return count;
}

static void print_dist(int **matrix, int **recover, int kilkist, int j) {
    int sum;
    int flag = 0;

    mx_printstr("Distance: ");
    for (int i = kilkist - 1; i >= 0; i--) {
        if (counter_ostr(recover, kilkist, j) == 2) {
            if (recover[j][i] != -1 && flag == 0) {
                mx_printint(matrix[recover[j][i]][recover[j][i - 1]]);
                flag++;
            }
        } else {
            if (recover[j][i] != -1) {
                sum = mx_dist_pr_same(matrix, recover, i, j);
                mx_printint(sum);
                break;
            }
        }
    }
}

static void print_path(char **ostrovi, int kilkist, int **recover) {
    int *sf = fprint_path(kilkist, recover);

    mx_printstr("Path: ");
    for (int i = 0; i < 2; i++) {
        mx_printstr(ostrovi[sf[i]]);
        if (i != 1) {
            mx_printstr(" -> ");
        }
    }
    mx_printchar('\n');
    free(sf);
}


void mx_print_same_path(char **ostrovi, int **matrix, int *arr, int **recover) {
    for (int i = 0; i < mx_cof_same(recover, arr[0]); i++) {
        if (mx_problem(recover, arr, i) == 0) 
            continue;
        mx_printstr("========================================\n");
        print_path(ostrovi, arr[0], recover);
        mx_printstr("Route: ");
        for (int j = arr[0] - 1; j >= 0; j--) {
            if (recover[i][j] != -1) {
                mx_printstr(ostrovi[recover[i][j]]);
                if (j != 0 && recover[i][j - 1] != -1) {
                    mx_printstr(" -> ");
                }
            }
        }
        mx_printchar('\n');
        print_dist(matrix, recover, arr[0], i);
        mx_printchar('\n');
        mx_printstr("========================================\n");
    }
}






