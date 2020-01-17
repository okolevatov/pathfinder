#include "../inc/pathfinder.h"

void mx_fix_audit(int *k_l_con, char **splite, int kilkisto) {
    int len = mx_strlen("error: invalid number of islands\n");

    if (k_l_con[2] < kilkisto) {
        write(2, "error: invalid number of islands\n", len);
        mx_del_strarr(&splite);
        free(k_l_con);
        exit(0);
    }
}
