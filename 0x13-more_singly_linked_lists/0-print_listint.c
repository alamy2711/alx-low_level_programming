#include "lists.h"

/**
 * print_listint - Prints all the elements of a listint_t list
 * @h: The header of listint_t list
 *
 * Return: The number of nodes
 */
size_t print_listint(const listint_t *h)
{
	int numNodes = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		numNodes++;
		h = h->next;
	}

	return (numNodes);
}
