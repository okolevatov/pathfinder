#include "../inc/pathfinder.h"

static int *fourth_check(int *k_l_con, char **splite, char **arr) {
    int er = 0;
    int len = mx_strlen("error: invalid number of islands\n");

    while (er < k_l_con[1]) {
        if (mx_strcmp(splite[k_l_con[0]], arr[er]) == 0) {
            k_l_con[1]--;
            k_l_con[0]++;
            break;
        } else if(mx_strcmp(splite[k_l_con[0]], arr[er]) != 0) {
            er++;
        }
        if (er == k_l_con[1]) {
        write(2, "error: invalid number of islands\n", len);
        mx_del_strarr(&splite);
        exit(0);
        }
    }
    return k_l_con; 
}

static int *first(int *k_l_con) {
    k_l_con[0]++;
    k_l_con[2]++;
    return k_l_con;
}

static char **second(int *k_l_con, char **splite, char **arr) {
    int rem = 0;

    while (rem < k_l_con[1] ) {
        if(mx_strcmp(splite[k_l_con[0]], arr[rem]) == 0) {
            k_l_con[1]--;
            k_l_con[0]++;
            break;
        } else if(mx_strcmp(splite[k_l_con[0]], arr[rem]) != 0) {
            rem++;
        }
        if (rem == k_l_con[1]) {
            arr[k_l_con[1]] = mx_strnew(mx_strlen(splite[k_l_con[0]]));
            mx_strcpy(arr[k_l_con[1]],splite[k_l_con[0]]);
            k_l_con = first(k_l_con);
        }
    }
    return arr;
}

char **mx_fix_audit1(int *k_l_con, char **splite, char **arr, int kilkisto) {
    if (k_l_con[1] == 0) {
        arr[k_l_con[1]] = mx_strnew(mx_strlen(splite[k_l_con[0]]));
        mx_strcpy(arr[k_l_con[1]],splite[k_l_con[0]]);
        k_l_con = first(k_l_con);
    } else if (k_l_con[1] > 0 && k_l_con[1] < kilkisto) {
        arr = second(k_l_con, splite, arr);
    } else if (k_l_con[1] >= kilkisto) {
        k_l_con = fourth_check(k_l_con, splite, arr);
    } 
    return arr;
}
