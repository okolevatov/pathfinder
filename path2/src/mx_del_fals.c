#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

static int counter(const char *str) {
	int count = 0;
	int len = mx_strlen(str);
	char *str1 = mx_strdup(str);

	for (int i = 0; i < len; i++) {
		if (str1[i] == ',' || (str1[i] > 47 && str1[i] < 58 )) {
			continue;
		} else {
			count++;
		}
	}
	mx_strdel(&str1);
	return count;
}

static char *stroka(const char *str) {
	int len = mx_strlen(str);
	char *str1 = mx_strdup(str);

	for (int j = 0; j < len; j++) {
		if(str1[j] == ',') {
			str1[j] = '-';
		} else if(str1[j] == '\n') {
			str1[j] = '-';
		} else if(str1[j] > 47 && str1[j] < 58 ) {
			str1[j] = '-';
		}
	}

	return str1;
}

static char *buffstroka(int count, char *str1, char *buff) {
	int k = 0;

	for (int j = 0; j < count - 1; j++) { 
  		if (str1[k] == '-') {
   			buff[j] = '-';
   			while(str1[k] == '-') {
    			k++;
   			}
  		} else {
   			buff[j] = str1[k];
   			k++;
  		}
 	}
 	mx_strdel(&str1);

 	return buff;
}

char *mx_del_fals(const char *str) {
	char *str1 = NULL; 
	int count = 0;
	char *buff = NULL;

	count = counter(str);
	buff = mx_strnew(count);
	str1 = stroka(str);
	buff = buffstroka(count, str1, buff);
	
 
 return buff;
}
