#include "../inc/pathfinder.h"

static void printerr (int count_n) {
    char *str1 = "error: line ";
    char *count = mx_itoa(count_n);
    char *str2 = mx_strjoin(str1, count);
    char *str3 = NULL; 

    str3 = mx_strjoin(str2, " is not valid\n");
    write(2, str3, mx_strlen(str3));
    mx_strdel(&str2);
    mx_strdel(&count);
}

void mx_error_space(char str, int count_n) {
    if (str == 9 
        || (str > 10 && str <= 13) 
        || str == ' ') {
        printerr(count_n + 1);
        exit(0);
    }
}
