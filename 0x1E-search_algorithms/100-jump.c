#include "search_algos.h"

/**
 * jump_search - Searches for a value in an array of integers using the
 * Jump search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: First index where value is located
 */
int jump_search(int *array, size_t size, int value)
{
	int start = 0, end = sqrt(size);

	if (array == NULL)
		return (-1);

	while (array[start] < value && start < (int)size)
	{
		printf("Value checked array[%d] = [%d]\n", start, array[start]);
		start += end;
	}

	start -= end;
	end += start;

	printf("Value found between indexes [%d] and [%d]\n", start, end);

	while (array[start] < value)
	{
		printf("Value checked array[%d] = [%d]\n", start, array[start]);
		start++;
	}

	if (array[start] == value)
	{
		printf("Value checked array[%d] = [%d]\n", start, array[start]);
		return (start);
	}

	return (-1);
}
