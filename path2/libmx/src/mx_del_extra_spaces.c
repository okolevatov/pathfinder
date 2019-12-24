#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str) {
	if(str == NULL) {
		return NULL;
	}
	char *buff = mx_strtrim(str);
	int count = 0;
	int k = 0;

	for(int i = 0; i < mx_strlen(buff); i++) {
		if(((buff[i] >= 9 && buff[i] <= 13) && (buff[i + 1] >= 9 && buff[i + 1] <= 13 )) 
			|| (buff[i] == 32 && buff[i + 1] == 32)
			|| (buff[i] == 82 && buff[i + 1] == 82)) {
			continue;
		} else {
			count++;
		}
	}

	char *buff2 = mx_strnew(count);
	for(int j = 0; j < count; j++) {
		if((buff[j] > 8 && buff[j] < 14) || (buff[j] == 32) || (buff[j] == 82)) {
			buff[j] = ' ';
		}	
	}
	for(int j = 0; j < count; j++) {
  		if(buff[k] == ' ') {
   			buff2[j] = ' ';
   			while(buff[k] == ' ') {
    			k++;
   			}
  	} else {
   		buff2[j] = buff[k];
   		k++;
  	}
 }

 	free(buff);
return buff2;
}
