#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

static int first(char *str) {
	int i = 0;

	while(str[i] != '\n') {
		i++;
	}
	return i;
}

static int second(char *str, int i) {
	int j = 0;
	char *number = mx_strnew(i);
	int kilkisto;

	while (str[j] != '\n') {
		number[j] = str[j];
		j++;
	}
	kilkisto = mx_atoi(number);
	mx_strdel(&number);
	return kilkisto;
}

static int *fourth(char *str) {
	int *k_l_con_i = (int*)(malloc)(sizeof(int) * (3));

	for (int j = 0; j < 4; j++) {
		k_l_con_i[j] = 0;
	}
	k_l_con_i[3] = first(str);
	return k_l_con_i;
}

char **mx_errors_isl(const char *str1) {
	char *str = mx_file_to_str(str1);
	int kilkisto;
	int *k_l_con_i = fourth(str);
	char **splite = NULL;
	char **arr = NULL;

	kilkisto = second(str, k_l_con_i[3]);
	k_l_con_i[3]++;
	splite = mx_helper_errors(k_l_con_i, str, kilkisto);
	arr = malloc (sizeof (char *) * (kilkisto + 1));
	for (; splite[k_l_con_i[0]] != 0; k_l_con_i[1]++) {
		arr = mx_fix_audit1(k_l_con_i, splite, arr, kilkisto);
	}
	mx_fix_audit(k_l_con_i, splite, kilkisto);
	arr[kilkisto] = 0;
	mx_del_strarr(&splite);
	mx_strdel(&str);
	free(k_l_con_i);
	return arr;
}
