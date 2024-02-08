#include "search_algos.h"

/**
 * advanced_binary_helper - Recursively performs advanced binary
 * search on a sorted array.
 *
 * @array: The integer array to search in.
 * @size: The size of the array.
 * @value: The value to search for.
 *
 * Return: Pointer to the found value or NULL if not found.
 */
int *advanced_binary_helper(int *array, size_t size, int value)
{
	size_t idx = 0;

	if (array == NULL || !size)
		return (NULL);

	/* Print the current subarray being searched */
	printf("Searching in array: ");
	for (idx = 0; idx < size; idx++)
		printf("%d%s", array[idx], idx + 1 == size ? "\n" : ", ");

	idx = (size - 1) / 2;

	/* Check if the middle element is the target value */
	if (array[idx] == value)
	{
		if (idx)
			return (advanced_binary_helper(array, idx + 1, value));
		return (array + idx);
	}
	else if (array[idx] > value)
		return (advanced_binary_helper(array, idx + 1, value));
	else
		return (advanced_binary_helper(array + idx + 1, size - idx - 1, value));
}

/**
 * advanced_binary - Performs advanced binary search on a sorted array.
 *
 * @array: The integer array to search in.
 * @size: The size of the array.
 * @value: The value to search for.
 *
 * Return: Index of the found value or -1 if not found.
 */
int advanced_binary(int *array, size_t size, int value)
{
	int *adv_bin = advanced_binary_helper(array, size, value);

	if (!adv_bin)
		return (-1);
	else
		return (adv_bin - array);
}
