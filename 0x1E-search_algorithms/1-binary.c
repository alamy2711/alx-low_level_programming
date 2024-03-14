#include "search_algos.h"

/**
 * binary_search - Searches for a value in a sorted array of integers
 * using the Binary search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: Index where value is located
 */
int binary_search(int *array, size_t size, int value)
{
	int start = 0, end = size - 1, mid, i;

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
