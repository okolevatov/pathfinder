 #include "../inc/libmx.h"

 int mx_read_line(char **lineptr, int buf_size, char delim, const int fd) {
 	int sz = 0, k = 0;
 	char c;
 	sz = read(fd, &c, 1);
 	lineptr = NULL;

 	if(sz < 0) {
		return -1;
	}

 	while(k < buf_size || c != delim || sz > 0) {
 		sz = read(fd, &c, 1);
 		k++;
 	}
 	
 	close(fd);

 	return k;
 }
