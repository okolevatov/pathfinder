#include "../inc/pathfinder.h"

int mx_is_digit_line(const char *p) {
    int i = 0;

    while (p[i] != '\n' && p[i] != '\0') { 
        if (p[i] < 48 || p[i] > 57) {
            return 0;
        }
        i++;
    }
    return 1;
}
