#include "../inc/pathfinder.h"

int mx_first_line(const char *argvv) {
    char *str = mx_file_to_str(argvv);
    int i = 0;
    int len = mx_strlen("error: line 1 is not valid\n");

    if (str[i] == '\n') {
        write(2,"error: line 1 is not valid\n", len);
        mx_strdel(&str);
        return 0;
    }
    if (str[i] == 48 && str[i + 1] == '\0') {
        write(2,"error: line 1 is not valid\n", len);
        mx_strdel(&str);
        return 0;
    }
    mx_strdel(&str);
    return 1;
}
