#include "lists.h"

/**
 * print_list - Prints all the elements of a list_t list
 * @h: The list_t list
 *
 * Return: The number of nodes
 */
size_t print_list(const list_t *h)
{
	const list_t *curr = h;
	size_t numNodes = 0;

	while (curr != NULL)
	{
		if (curr->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", curr->len, curr->str);

		numNodes++;
		curr = curr->next;
	}
	return (numNodes);
}
