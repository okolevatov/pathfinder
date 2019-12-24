#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

static void printerr (int count_n) {
	char *str1 = "error: line ";
	char *counter = mx_itoa(count_n);
	char *str2 = mx_strjoin(str1, counter);
	char *str3 = NULL;

	str3 = mx_strjoin(str2, " is not valid\n");
	write(2, str3, mx_strlen(str3));
	free(str2);
	free(counter);
	free(str3);
}

void mx_loop(const char *str1) {
	char *str = mx_file_to_str(str1);
	char *arr = mx_del_fals(str);
	char **arr1 = mx_strsplit(arr, '-');
	int line_counter = 1;

	for (int i = 0; arr1[i] != 0; i = i + 2) {
		if ((i % 2) == 0) {
			line_counter++;
		}
		if (mx_strcmp(arr1[i], arr1[i + 1]) == 0) {
			printerr(line_counter);
			exit(0);
		}
	}
	free(str);
	free(arr);
	mx_del_strarr(&arr1);
}
