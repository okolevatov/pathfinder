#include "../inc/libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
	unsigned long buff = 0;
	unsigned long copy = nbr;
	int k = 0;

	if(nbr == 0) {
		return 0;
	}

	while(nbr > 0) {
		nbr = nbr / 16;
		k++;
	}
	char* arr = mx_strnew(k);

	for(int i = k - 1; i >= 0; i--) {
		buff = copy % 16;
		if(buff >= 10 && buff <= 15) {
			arr[i] = buff + 87;
		} else if(buff >= 0 && buff <= 9) {
			arr[i] = buff + 48;
		}
		copy = copy / 16;
	}
	return arr;
}
