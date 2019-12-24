 #include "../inc/libmx.h"

 void mx_push_back(t_list **list, void *data) {
 	if(*list == 0) {
		*list = mx_create_node(data);
		return;
	}
	
	t_list *newNode = mx_create_node(data);
	t_list *tmp = *list;

	while(tmp->next != NULL) {
		tmp = tmp -> next;
	}
	tmp->next = newNode;
 }
