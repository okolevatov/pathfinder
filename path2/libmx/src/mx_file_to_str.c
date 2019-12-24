#include "../inc/libmx.h"

char *mx_file_to_str(const char *file) {
	int fopen = open(file, O_RDONLY);
    int len = 0;
    char *str = NULL;
    char c = 0;

    if (fopen < 0)
        return NULL;

    while (read(fopen, &c, 1))
        len++;

    close(fopen);

    if (len <= 0)
        return NULL;

    fopen = open(file, O_RDONLY);
    str = mx_strnew(len);

    for (int i = 0; read(fopen, &c, 1); i++)
        str[i] = c;

    close(fopen);
    
    return str;
}
