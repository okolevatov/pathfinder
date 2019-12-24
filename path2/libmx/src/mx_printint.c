#include "../inc/libmx.h"

void mx_printint(int n) {
	int reverse = 0;
	int last = n % 10;
	int count = 0;

	
	if(n / 10 == 0 && n < 0) {
		mx_printchar('-');
		n = n * (-1);
		mx_printchar(n + 48);
	} else {
	n = n / 10;

	if(n < 0) {
		mx_printchar('-');
		n = n * (-1);
		last = -last;
		
	}
		
	while(n != 0) {
		reverse = reverse * 10 + n % 10;
		n = n /10;
		count++;
	}
	for(int i = 0; i < count; ++i) {
		mx_printchar(reverse % 10 + 48);
		reverse /= 10;
	}
	mx_printchar(last + 48);
	}
}

