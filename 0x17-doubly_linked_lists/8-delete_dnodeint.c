#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at a given position in the list
 * @head: The head list
 * @index: Index
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *tmp = *head, *curr = *head;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;

		if (*head != NULL)
			(*head)->prev = NULL;

		free(tmp);
		return (1);
	}

	while (i < index)
	{
		if (curr == NULL)
			return (-1);

		curr = curr->next;
		i++;
	}

	if (curr == NULL)
		return (-1);

	if (curr->prev != NULL)
		curr->prev->next = curr->next;

	if (curr->next != NULL)
		curr->next->prev = curr->prev;

	free(curr);

	return (1);
}
