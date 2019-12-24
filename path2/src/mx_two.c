#include "../libmx/inc/libmx.h"

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

static void mx_free(char str1, char str2, int count_n) {
	if (str1 == '\n' && str2 == '-') {
		printerr(count_n + 2);
		exit(0);
	} else if (str1 == '-' && str2 == ',') {
		printerr(count_n + 1);
		exit(0);
	} else if (str1 == ',' && str2 == '0') {
		printerr(count_n + 1);
		exit(0);
	} else if (((str1 >= 65 && str1 <= 90) 
		|| (str1 >= 97 && str1 <= 122)) 
	&& (str2 >= 48 && str2 <= 57)) {
		printerr(count_n + 1);
		exit(0);
	}
}

void mx_two(char a, char b, int count_n) {
	if (a != '\n' && b == '\0') {
		printerr(count_n + 1);
		exit(0);
	}
	if (((a < 65 || a > 90) 
		&& (a < 97 || a > 122))
		&& (a != '\n' 
			&& a != '-' 
			&& a != ',')
		&& (a < 48 || a > 57)) {
		printerr(count_n + 1);
		exit(0);
	}
	if(a == ',' && (b < 48 || b > 57)) {
		printerr(count_n + 1);
		exit(0);
	}
	mx_free(a, b, count_n);
}
