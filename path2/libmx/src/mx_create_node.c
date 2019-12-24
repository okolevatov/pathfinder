#include "../inc/libmx.h"

t_list  *mx_create_node(void *data) {
	t_list *head = NULL;
	head = malloc(sizeof(t_list));
	if(head == NULL) {
		return NULL;
	}
	head->data = data;
	head->next = NULL;

	return head;
}
