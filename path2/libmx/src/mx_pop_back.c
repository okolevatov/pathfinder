#include "../inc/libmx.h"

void mx_pop_back(t_list **head) {

	if((*head) == NULL || head == NULL) {
		return;
	}
	if((*head) -> next == NULL) {
		free(*head);
		(*head)->data = NULL;
		(*head)->next = NULL;
	} else { 
		t_list *buff = *head;

		while(buff -> next -> next != NULL) {
			buff = buff -> next;
		}
		free(buff->next);
		buff->next->data = NULL;
		buff->next = NULL;
		
	}
}
