#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array using
 * jump search algorithm.
 *
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: Value to search for.
 *
 * Return: Index of the value in the array if found, otherwise -1.
 */
int jump_search(int *array, size_t size, int value)
{
	size_t current, pace, jump;

	if (array == NULL || size == 0)
		return (-1);

	pace = (int)sqrt((double)size);
	current = jump = 0;
	while (jump < size && array[jump] < value)
	{
		printf("Value checked array[%ld] = [%d]\n", jump, array[jump]);
		current = jump;
		jump += pace;
	}

	printf("Value found between indexes [%ld] and [%ld]\n", current, jump);

	jump = jump > size - 1 ? jump : size - 1;
	while (current < jump && array[current] < value)
	{
		printf("Value checked array[%ld] = [%d]\n", current, array[current]);
		current++;
	}

	printf("Value checked array[%ld] = [%d]\n", current, array[current]);

	return (array[current] == value ? (int)current : -1);
}
