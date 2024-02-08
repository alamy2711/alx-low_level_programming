#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array using
 * the jump search algorithm.
 *
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: Value to search for.
 *
 * Return: Index of the value in the array if found, otherwise -1.
 */
int jump_search(int *array, size_t size, int value)
{
	size_t start = 0, end = sqrt(size);

	if (!array)
		return (-1);

	/* Jumping to blocks */
	while (start < size && array[start] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", start, array[start]);
		start += end;
	}

	end = start - end;
	printf("Value found between indexes [%lu] and [%lu]\n", end, start);
	start = start >= size ? size - 1 : start;

	/* Linear search within block */
	while (end <= start)
	{
		printf("Value checked array[%lu] = [%d]\n", end, array[end]);
		if (array[end] == value)
			return (end);
		end++;
	}

	return (-1);
}
