#include "lists.h"

/* Prototypes */
size_t circular_list_len(listint_t *head);

/**
 * free_listint_safe - Frees a listint_t list (safe version)
 * @h: Head of the listint_t list
 *
 * Return: The size of the list that was free’d
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *temp;
	size_t i, numNodes, listSize = 0;

	if (h == NULL || *h == NULL)
		return (0);

	numNodes = circular_list_len(*h);

	for (i = 0; i < numNodes; i++)
	{
		temp = *h;
		*h = (*h)->next;
		listSize += sizeof(temp);
		free(temp);
	}
	*h = NULL;

	return (listSize);
}

/**
 * circular_list_len - Calculates number of nodes in a circular listint_t list
 * @head: Head of the listint_t list
 *
 * Return: Number of nodes in a circular listint_t list
 */
size_t circular_list_len(listint_t *head)
{
	listint_t *curr, *originHead = head;
	size_t i, numNodes = 0;

	while (head != NULL)
	{
		for (i = 0, curr = originHead; i < numNodes; i++, curr = curr->next)
		{
			if (curr == head)
				return (numNodes);
		}
		numNodes++;
		head = head->next;
	}

	return (numNodes);
}
