 #include "../inc/libmx.h"

void mx_pop_front(t_list **head) {
	if((*head != NULL) && (head != NULL)) {
		t_list *buff = *head;
		*head = (*head)->next;
		free(buff);
		buff->data = NULL;
		buff->next = NULL;
	}
}
