#include "../libmx/inc/libmx.h"

void mx_free_rout(int *new, int *sf_same) {
	free(new);
	free(sf_same);

	new = NULL;
	sf_same = NULL;
}
