#include "../inc/pathfinder.h"

static void third_check(int kilkisto, char *str) {
    int len = mx_strlen("error: invalid number of islands\n");

    if (kilkisto <= 0) {
        write(2, "error: invalid number of islands\n", len);
        mx_strdel(&str);
        exit(0);
    } 
}

char **mx_helper_errors(int *k_l_con_i, char *str, int kilkisto) {
    char *new = mx_del_fals(&str[k_l_con_i[3]]);
    char **splite = mx_strsplit(new, '-');

    mx_strdel(&new);
    third_check(kilkisto, str);
    return splite;
}
