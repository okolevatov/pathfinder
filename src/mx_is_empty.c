#include "../inc/pathfinder.h"

void mx_is_empty(const char *argvv) {
    char *str2 = mx_strdup(argvv);
    int lenargv = mx_strlen(str2);
    char *str3 = mx_strjoin("error: file ", str2);
    char *enter = mx_strjoin(str3, " is empty\n");

    write(2, enter , 23 + lenargv);
    mx_strdel(&str2);
    mx_strdel(&str3);
    mx_strdel(&enter);
}
