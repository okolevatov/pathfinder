#include "../libmx/inc/libmx.h"

int **mx_creating_arr(int *arr, int *alcopy, int kilkist) {
	int **conc = (int **) malloc (sizeof (int *) * (2));

	conc[0] = (int*)(malloc)(sizeof(int) * (2));
	conc[1] = (int*)(malloc)(sizeof(int) * (kilkist));
	conc[0][0] = arr[0];
	conc[0][1] = arr[1];
	for (int i = 0; i < kilkist; i++) {
		conc[1][i] = alcopy[i];
	}

	return conc;
}
