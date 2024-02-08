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
	size_t step, step_size;
	listint_t *current, *jump;

	if (list == NULL || size == 0)
		return (NULL);

	step = 0;
	step_size = sqrt(size);

	/* Jumping through the list */
	for (current = jump = list; jump->index + 1 < size && jump->n < value;)
	{
		current = jump;
		for (step += step_size; jump->index < step; jump = jump->next)
		{
			if (jump->index + 1 == size)
				break;
		}
		printf("Value checked at index [%ld] = [%d]\n", jump->index, jump->n);
	}

	printf("Value found between indexes [%ld] and [%ld]\n", current->index,
	jump->index);

	/* Linear search within the found range */
	for (; current->index < jump->index && current->n < value;
	current = current->next)
		printf("Value checked at index [%ld] = [%d]\n", current->index,
		current->n);
	printf("Value checked at index [%ld] = [%d]\n", current->index,
	current->n);

	return (current->n == value ? current : NULL);
}
