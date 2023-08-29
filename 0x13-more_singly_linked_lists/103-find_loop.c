#include "lists.h"

/**
 * find_listint_loop - Finds the loop in a linked list
 * @head: Head of the listint_t list
 *
 * Return: The address of the node where the loop starts
 * or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *curr, *originHead = head;
	size_t i, numNodes = 0;

	if (head == NULL)
		return (NULL);

	while (head != NULL)
	{
		for (i = 0, curr = originHead; i < numNodes; i++, curr = curr->next)
		{
			if (curr == head)
				return (curr);
		}
		numNodes++;
		head = head->next;
	}
	return (NULL);
}
