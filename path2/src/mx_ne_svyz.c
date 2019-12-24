#include "../libmx/inc/libmx.h"

void mx_ne_svyz(int *en_b_w_k_b) {
	en_b_w_k_b[5]++;

	if(en_b_w_k_b[5] > 2147483) {
		exit(0);
	}
}
