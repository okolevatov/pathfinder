#include "../inc/pathfinder.h"

static int **matrix(int kilkisto) {
    int **arr = (int **) malloc (sizeof (int *) * (kilkisto));

    for (int q = 0; q < kilkisto; q++) {
        arr[q] = (int*)(malloc)(sizeof(int) * (kilkisto));
        for (int j = 0; j < kilkisto; j++) {
            if (q == j) {
                arr[q][j] = 0;
            } else arr[q][j] = 2147483647;
        }
    }
    return arr;
}

static char **arrcheckk(char *str) {
    char *help = mx_replace_substr(str, ",", "-");
    char *withdefis = mx_replace_substr(help, "\n", "-");
    char **arrchek = mx_strsplit(withdefis, '-');

    mx_strdel(&withdefis);
    mx_strdel(&help);
    return arrchek;
}

static int **matrix_enter(char **ostrovi, int **matrix, char *str) { 
    int *rc_coc = (int*)(malloc)(sizeof(int) * (4));
    char **arrchek = arrcheckk(str);

    for (int x = 0; x < 3; x++) {
        rc_coc[x] = 0; 
    }
    rc_coc[3] = 2;
    for (int i = 0; arrchek[i]; i++) { 
        if (arrchek[i][0] > 47 && arrchek[i][0] < 58) {
            matrix[rc_coc[0]][rc_coc[1]] = mx_atoi(arrchek[rc_coc[3]]);
            matrix[rc_coc[1]][rc_coc[0]] = mx_atoi(arrchek[rc_coc[3]]);
            rc_coc[3] = rc_coc[3] + 3;
            continue;
        }
        rc_coc = mx_helper_matrix(rc_coc, arrchek, ostrovi, i);
    }
    mx_del_strarr(&arrchek);
    free(rc_coc);
    return matrix;
}

static int cicle(char *str, int ij) {
    while(str[ij] != '\n') { 
        ij++;
    }
    ij++;
    return ij;
}

int **mx_matrix_graph(char *file, char **ostrovi) { 
    char *str = mx_file_to_str(file);
    int ij[2] = {0,0};
    int kilkisto;
    char *number = NULL;
    int **matrixarr = NULL;

    ij[0] = cicle(str, ij[0]);
    number = mx_strnew(ij[0]);
    while (str[ij[1]] != '\n') { 
        number[ij[1]] = str[ij[1]];
        ij[1]++; 
    }
    kilkisto = mx_atoi(number);
    mx_strdel(&number);
    matrixarr = matrix(kilkisto);
    matrixarr = matrix_enter(ostrovi, matrixarr, &str[ij[0]]);
    mx_strdel(&str);
    return matrixarr; 
}
