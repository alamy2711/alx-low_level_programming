#include "lists.h"

/**
 * list_len - Count the number of elements in a linked list_t list
 * @h: The list_t list
 *
 * Return: The number of elements in a linked list_t list
 */
size_t list_len(const list_t *h)
{
	const list_t *curr = h;
	size_t numNodes = 0;

	while (curr != NULL)
	{
		numNodes++;
		curr = curr->next;
	}

	return (numNodes);
}
