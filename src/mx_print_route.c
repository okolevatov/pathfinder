#include "../inc/pathfinder.h"

static int *fprint_path(int kilkist, int **recover, int p) {
    int *sf = (int*)(malloc)(sizeof(int) * (2));
    int flag = 0;

    for (int i = p; i < p + 1; i++) {
        for (int j = kilkist - 1; j >= 0; j--) {
            if (recover[i][j] != -1) {
                flag = 1;
            }
            if (flag == 1) {
                sf[0] = recover[i][j];
                while(j != 0 && recover[i][j - 1] != -1) {
                    j--;
                }
                sf[1] = recover[i][j];
                break;
            }
        }
    }
    return sf;
}

static int *print_path(char **ostrovi, int kilkist, int **recover, int p) {
    int *sf = fprint_path(kilkist, recover, p);

    mx_printstr("Path: ");
    for (int i = 0; i < 2; i++) {
        mx_printstr(ostrovi[sf[i]]);
        if (i != 1) {
            mx_printstr(" -> ");
        }
    }
    mx_printchar('\n');
    return sf;
}

static int counter_ostr(int **recover, int p, int kilkist) {
    int count = 0;

    for (int i = kilkist - 1; i >= 0; i--) {
        if (recover[p][i] != -1) {
            count++;
        }
    }
    return count;
}

static void print_dist(int **matrix, int **recover, int kilkist, int p) {
    int sum;
    int flag = 0;

    mx_printstr("Distance: ");
    for (int i = kilkist - 1; i >= 0; i--) {
        if (counter_ostr(recover, p, kilkist) == 2) {
            if (recover[p][i] != -1 && flag == 0) {
                mx_printint(matrix[recover[p][i]][recover[p][i - 1]]);
                flag++;
            }
        } else {
            if (recover[p][i] != -1) {
                sum = mx_dist_pr(matrix, recover, p, i);
                mx_printint(sum);
                break;
            }
        }
    }
}

void mx_print_route(char **ostrovi, int **matrix, int **recover, int **conc1) {
    int **new = NULL;
    int *sf = NULL;
    int *sf_same = NULL;

    for (int i = conc1[0][1] + 1; i < conc1[0][0]; i++) {
        if (mx_test_same(conc1[1], matrix, i, conc1[0][0]) >= 2) {
            new  = mx_same_path2(matrix, i, conc1[1], conc1[0]);
            mx_sort_arr(new, conc1[0][0]);
            sf_same = mx_fprint_same(conc1[0][0], new);
            mx_print_same_path(ostrovi, matrix, conc1[0], new);
            mx_free_rout(new, sf_same, conc1[0][0]);
            continue;
        }
        mx_printstr("========================================\n");
        sf = print_path(ostrovi, conc1[0][0], recover, i); 
        mx_print_sm(i, recover, ostrovi, conc1[0][0]);
        print_dist(matrix, recover, conc1[0][0], i);
        mx_printstr("\n========================================\n");
        free(sf);
    }   
}
