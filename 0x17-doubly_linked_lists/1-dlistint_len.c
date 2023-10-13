#include "lists.h"

/**
 * dlistint_len - Counts the number of nodes in a doubly linked list
 * @h: List head
 *
 * Return: The number of nodes in the list
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t numNodes = 0;

	while (h != NULL)
	{
		numNodes++;
		h = h->next;
	}
	return (numNodes);
}
