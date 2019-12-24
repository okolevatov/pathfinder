#include "../inc/libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
	const char *sf = s1;
	const char *ss = s2;

	for(size_t i = 0; i < n; i++) {
		if(sf[i] != ss[i]) {
			return sf[i] - ss[i];
		}
	}
	
	return 0;
}
