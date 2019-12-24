#include "../inc/libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
	t_list *i, *j;
	

	 for (i = lst; i != NULL; i = i->next) {
  		for (j = i->next; j != NULL; j = j->next) {
			if(true == cmp(i->data, j->data)) {
				t_list *tmp = i->data;
				i->data = j->data;
				j->data = tmp;
				tmp = NULL;
			}
		}
	}
	j = NULL;
	i = NULL;

	return lst;
}
