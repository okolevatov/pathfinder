#include "../inc/pathfinder.h"

static int isdigit(int c) {
    if (48 <= c && c <= 57) {
        return 1;
    } else return 0;
}
static int isspace(char c) {
    if (c == '\t' ||
        c == '\n' ||
        c == '\v' || 
        c == '\f' ||
        c == '\r' ||
        c == ' ') {
        return 1;
    } else return 0;
}

int mx_atoi(const char *str) {
    int i = 0;
    int sum = 0;
    int sign = 1;

    while (isspace(str[i]) == 1) {
        i++;
    }
    if (str[i] == '-') {
        sign = -1;
        i++;
    }
    while (isdigit(str[i]) == 1) {
        sum = sum * 10 + (str[i] - '0');
        i++;
    }
    return sum * sign;
}
