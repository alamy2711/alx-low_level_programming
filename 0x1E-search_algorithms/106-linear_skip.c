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
	skiplist_t *current, *jump;

	if (list == NULL)
		return (NULL);

	/* Iterating through the list */
	for (current = jump = list; jump->next != NULL && jump->n < value;)
	{
		current = jump;
		if (jump->express != NULL)
		{
			jump = jump->express;
			printf("Value checked at index [%ld] = [%d]\n",
			jump->index, jump->n);
		}
		else
		{
			while (jump->next != NULL)
				jump = jump->next;
		}
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
	current->index, jump->index);

	/* Linear search within the found range */
	for (; current->index < jump->index && current->n < value;
	current = current->next)
		printf("Value checked at index [%ld] = [%d]\n",
		current->index, current->n);
	printf("Value checked at index [%ld] = [%d]\n",
	current->index, current->n);

	return (current->n == value ? current : NULL);
}
