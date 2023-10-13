#include "lists.h"

/**
 * free_dlistint - Frees a doubly linked list
 * @head: List head
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
