#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

static int firstcheck(int argcc) {
	int len = mx_strlen("usage: ./pathfinder [filename]\n");

	if (argcc <= 1 || argcc > 2) {
		write(2,"usage: ./pathfinder [filename]\n", len);
		return 0;
	} 
	return 1;
}

static int secondcheck(const char *argvv ) {
	int fp = open(argvv, O_RDONLY);
	char *str2 = mx_strdup(argvv);
	int lenargv = mx_strlen(str2);
	char *str3 = mx_strjoin("error: file ", str2);
	char *enter = mx_strjoin(str3, " does not exist\n");

	if (fp < 0) {
		close(fp);
		write(2, enter , 29 + lenargv);
		return 0;
	}
	mx_strdel(&str2);
    mx_strdel(&str3);
    mx_strdel(&enter);
	close(fp);
	return 1;
}

static int thirdcheck(const char *argvv) {
	int fp = open(argvv, O_RDONLY);
	char c;
	int sz = read(fp, &c, 1);

	if (sz <= 0) {
		close(fp);
		mx_is_empty(argvv);
		return 0;
	}

	close(fp);
	return 1;
}

static int fourthcheck(const char *argvv) {
	char *str = mx_file_to_str(argvv);
	int len = mx_strlen("error: line 1 is not valid\n");

	if (mx_is_digit_line(str) == 0) {
		write(2,"error: line 1 is not valid\n", len);
		mx_strdel(&str);
		return 0;
	}
	mx_first_zero(str);
	mx_strdel(&str);
	return 1;
}

int mx_errors_check(int argcc, const char *argvv) {
	if (firstcheck(argcc) == 0) {
		return 0;
	}
	if (secondcheck(argvv) == 0) {
		return 0;
	}
	if (thirdcheck(argvv) == 0) {
		return 0;
	}
	if (fourthcheck(argvv) == 0) {
		return 0;
	}
	return 1;
}
