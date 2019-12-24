#include "../libmx/inc/libmx.h"

int *mx_helper_matrix(int *rc_coc, char **arrchek, char **ostrovi, int i) {
	for (int j = 0; ostrovi[j]; j++) {
		if (rc_coc[2] == 1 && (mx_strcmp(ostrovi[j],arrchek[i]) == 0)) {
			rc_coc[2] = 0;
			rc_coc[1] = j;
			continue;
		}
		if (rc_coc[2] == 0 && (mx_strcmp(ostrovi[j],arrchek[i]) == 0)) {
			rc_coc[0] = j;
			rc_coc[2]++;
		}
	}
	return rc_coc;
}
