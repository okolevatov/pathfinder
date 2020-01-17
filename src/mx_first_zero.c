#include "../inc/pathfinder.h"

static int is_digit(char *p) {
    int i = 0;

    while (p[i] != '\n' && p[i] != '\0') { 
        if (p[i] < 48 || p[i] > 57) {
            return 0;
        }
        i++;
    }
    return i;
}

static void only_number(char *str) {
    int i;
    int len = mx_strlen("error: line 2 is not valid\n");

    i = is_digit(str);
    if (str[i] == '\n' && str[i + 1] == '\0') {
        write(2,"error: line 2 is not valid\n", len);;
        exit(0);
    }
}

void mx_first_zero(char *str) {
    int len = mx_strlen("error: line 1 is not valid\n");

    if (str[0] == '0' && str[1] == '\0') {
        write(2,"error: line 1 is not valid\n", len);;
        exit(0);
    } else if (str[0] == '0' 
        && str[1] == '\n' 
        && str[2] == '\0') {
        write(2,"error: line 2 is not valid\n", len);
        exit(0);
    }
    only_number(str);
}
