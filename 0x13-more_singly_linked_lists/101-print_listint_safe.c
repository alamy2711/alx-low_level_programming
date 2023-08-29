#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list
 * @head: Head of the listint_t list
 *
 * Return: The number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *originHead = head, *curr;
	size_t numNode = 0, i;

	if (head == NULL)
		return (0);

	while (head != NULL)
	{
		for (i = 0, curr = originHead; i < numNode; i++, curr = curr->next)
		{
			if (curr == head)
			{
				printf("-> [%p] %d\n", (void *)head, head->n);
				return (numNode);
			}
		}

		printf("[%p] %d\n", (void *)head, head->n);
		numNode++;
		head = head->next;
	}

	return (numNode);
}
