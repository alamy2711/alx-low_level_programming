#include "search_algos.h"

/**
 * _binary_search - Searches for a value in a sorted array of integers
 * using the Binary search algorithm
 * @array: Pointer to the first element of the array to search in
 * @start: Start of the range to search in
 * @end: End of the range to search in
 * @value: Value to search for
 *
 * Return: Index where value is located
 */
int _binary_search(int *array, int start, int end, int value)
{
	int mid, i;

	if (array == NULL)
		return (-1);

	while (start <= end)
	{
		mid = (start + end) / 2;
		printf("Searching in array: ");

		for (i = start; i <= end; i++)
		{
			printf("%d", array[i]);
			if (i != end)
				printf(", ");
			else
				printf("\n");
		}

		if (array[mid] == value)
			return (mid);
		else if (value < array[mid])
			end = mid - 1;
		else if (value > array[mid])
			start = mid + 1;
	}

	return (-1);
}

/**
 * exponential_search - Searches for a value in an array of integers using the
 * Exponential search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: First index where value is located
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t i = 1;

	if (array == NULL)
		return (-1);

	if (array[0] == value)
		return (0);

	while (i < size && array[i] <= value)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		i *= 2;
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
		   i / 2, i < size - 1 ? i : size - 1);

	return (_binary_search(array, i / 2, i < size - 1 ? i : size - 1, value));
}
