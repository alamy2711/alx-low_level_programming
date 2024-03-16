#include "search_algos.h"

/**
 * linear_skip - Searches for a value in a sorted singly linked list using
 * linear skip.
 *
 * @list: A pointer to the head of the linked list to search.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the head of the list is NULL, NULL.
 * Otherwise, a pointer to the first node where the value is located.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current, *jumper;

	if (!list)
		return (NULL);

	/* Iterating through the list */
	current = jumper = list;
	while (jumper->next != NULL && jumper->n < value)
	{
		current = jumper;
		if (jumper->express != NULL)
		{
			jumper = jumper->express;
			printf("Value checked at index [%ld] = [%d]\n",
				   jumper->index, jumper->n);
		}
		else
		{
			while (jumper->next != NULL)
				jumper = jumper->next;
		}
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
		   current->index, jumper->index);

	/* Linear search within the found range */
	while (current->index < jumper->index && current->n < value)
	{
		printf("Value checked at index [%ld] = [%d]\n",
			   current->index, current->n);
		current = current->next;
	}
	printf("Value checked at index [%ld] = [%d]\n",
		   current->index, current->n);

	return (current->n == value ? current : NULL);
}
