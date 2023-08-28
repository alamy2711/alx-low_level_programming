#include "lists.h"

/**
 * listint_len - Counts the number of elements in a linked listint_t list
 * @h: The header of listint_t list
 *
 * Return: The number of elements in a linked listint_t list.
 */
size_t listint_len(const listint_t *h)
{
	int numNodes = 0;

	while (h != NULL)
	{
		numNodes++;
		h = h->next;
	}

	return (numNodes);
}
