#include "search_algos.h"

/**
 * jump_list - Searches for a value in a singly linked list using
 * jump search algorithm.
 *
 * @list: Pointer to the head node of the linked list.
 * @size: The size of the linked list.
 * @value: The value to search for.
 *
 * Return: Pointer to the node containing the value if found, otherwise NULL.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t pace, pace_size;
	listint_t *current, *jumper;

	if (list == NULL || size == 0)
		return (NULL);

	pace = 0;
	pace_size = sqrt(size);

	/* Jumping through the list */
	for (current = jumper = list; jumper->index + 1 < size && jumper->n < value;)
	{
		current = jumper;
		for (pace += pace_size; jumper->index < pace; jumper = jumper->next)
		{
			if (jumper->index + 1 == size)
				break;
		}
		printf("Value checked at index [%ld] = [%d]\n", jumper->index, jumper->n);
	}

	printf("Value found between indexes [%ld] and [%ld]\n", current->index,
	jumper->index);

	/* Linear search within the found range */
	for (; current->index < jumper->index && current->n < value;
	current = current->next)
		printf("Value checked at index [%ld] = [%d]\n", current->index,
		current->n);
	printf("Value checked at index [%ld] = [%d]\n", current->index,
	current->n);

	return (current->n == value ? current : NULL);
}
