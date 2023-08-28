#include "lists.h"

/**
 * get_nodeint_at_index - Gets the nth node of a listint_t linked list
 * @head: The head of the listint_t list
 * @index: The idndex to search for
 *
 * Return: The nth node of a listint_t linked list
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i;

	if (head == NULL)
		return (NULL);

	for (i = 0; head != NULL && i != index; i++)
		head = head->next;

	if (i != index)
		return (NULL);

	return (head);
}
