#include "search_algos.h"

/**
 * binary_search - Search for a value in a sorted array using binary search.
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 * @value: Value to search for.
 *
 * Return: Index of the value in the array if found, otherwise -1.
 */
int binary_search(int *array, size_t size, int value)
{
	size_t left, right, mid, i;

	if (array == NULL)
		return (-1);

	for (left = 0, right = size - 1; right >= left;)
	{
		printf("Searching in array: ");
		for (i = left; i < right; i++)
			printf("%d, ", array[i]);
		printf("%d\n", array[i]);

		mid = left + (right - left) / 2;
		if (array[mid] == value)
			return (mid);
		if (array[mid] > value)
			right = mid - 1;
		else
			left = mid + 1;
	}

	return (-1);
}

/**
 * exponential_search - Search for a value in a sorted array using
 * exponential search.
 *
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: Value to search for.
 *
 * Return: Index of the value in the array if found, otherwise -1.
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t index = 1, size_new = 0;
	int result;

	if (array == NULL || !size)
		return (-1);

	/* Finding the range for binary search */
	while (index < size && array[index] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", index, array[index]);
		index <<= 1;
	}

	size_new = (index >= size ? size : index + 1) - (index >> 1);
	index >>= 1;

	printf("Value found between indexes [%lu] and [%lu]\n",
	index, (index << 1) >= size ? size - 1 : index << 1);

	/* Performing binary search within the found range */
	result = binary_search(array + index, size_new, value);
	return (result == -1 ? result : result + (int)index);
}
