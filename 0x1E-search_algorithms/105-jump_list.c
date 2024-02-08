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
	size_t currentIndex = 0, jump = sqrt(size), lastJumpIndex = 0;
	listint_t *lastNode = list;

	if (!list)
		return (NULL);
	/* Jumping through the list */
	while (list->n < value)
	{
		for (lastJumpIndex = currentIndex, lastNode = list, jump = 0;
		list->next && jump < sqrt(size); jump++)
		{
			list = list->next;
			currentIndex++;
		}
		printf("Value checked at index [%lu] = [%d]\n", currentIndex, list->n);
		if (!list->next)
			break;
	}
	/* Adjusting the jump index */
	if (!list->next)
		jump = lastJumpIndex;
	else
		jump = currentIndex >= sqrt(size) ? currentIndex - sqrt(size) : 0;
	printf("Value found between indexes [%lu] and [%lu]\n", jump,
	currentIndex);

	currentIndex = currentIndex >= size ? size - 1 : currentIndex;
	list = lastNode;
	/* Linear search within the block */
	while (list)
	{
		printf("Value checked at index [%lu] = [%d]\n", jump, list->n);
		if (list->n == value)
			return (list);
		jump++;
		list = list->next;
	}

	return (NULL);
}
