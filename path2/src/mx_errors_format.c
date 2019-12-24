#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

static void printerr (int count_n, char *str) {
	char *str1 = "error: line ";
	char *counter = mx_itoa(count_n);
	char *str2 = mx_strjoin(str1, counter);
	char *str3 = NULL;

	str3 = mx_strjoin(str2, " is not valid\n");
	write(2, str3, mx_strlen(str3));
	mx_strdel(&str);
	mx_strdel(&str2);
	mx_strdel(&counter);
}

static int dash_count (int dash, char str) {
	if (str == '-') {
		dash++;
	}
	return dash;
}

static void dash_control(int *dash_n_point, int p, char *str) {
	if (dash_n_point[1] > 1) {
		if (mx_is_digit_line(&str[p]) == 0 
			|| dash_n_point[0] != 1 
			|| dash_n_point[2] != 1) 
		{
			printerr(dash_n_point[1], str);
			exit(0);
		}
	}
}

static void check1(int *dash_n_point, int p, char *str) {
	dash_n_point[1]++;
	dash_control(dash_n_point, p, str);
	dash_n_point[0] = 0;
	dash_n_point[2] = 0;
}

int mx_errors_format (const char *argvv) {
	char *str = mx_file_to_str(argvv);
	int lenstr = mx_strlen(str);
	int dash_n_point[3] = {0,0,0};
	int p = 0;

	for (int i = 0; i < lenstr; i++ ) {
		dash_n_point[0] = dash_count(dash_n_point[0], str[i]);
		if(str[i] == ',') {
			dash_n_point[2]++;
			p = i + 1;
		}
		mx_error_space(str[i], dash_n_point[1]);
		mx_two(str[i], str[i + 1], dash_n_point[1]);
		if (str[i] == '\n' || str[i + 1] == '\0') {
			check1(dash_n_point, p, str);
		}
	}
	mx_strdel(&str);
	return 1;
}
