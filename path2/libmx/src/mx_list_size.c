#include "../inc/libmx.h"

int mx_list_size(t_list *list) {
	if(list == NULL) {
		return 0;
	}
	int count = 1;
	t_list *buff = list;

	while(buff->next != NULL) {
		count++;
		buff = buff -> next;
	}

	return count;
}
