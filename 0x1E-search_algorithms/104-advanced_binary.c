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
	size_t i = 0;

	if (!size || !array)
		return (NULL);

	/* Print the current subarray being searched */
	printf("Searching in array: ");
	for (i = 0; i < size; i++)
		printf("%d%s", array[i], i + 1 == size ? "\n" : ", ");

	i = (size - 1) / 2;

	/* Check if the middle element is the target value */
	if (array[i] == value)
	{
		if (i)
			return (advanced_binary_helper(array, i + 1, value));
		return (array + i);
	}
	else if (array[i] > value)
		return (advanced_binary_helper(array, i + 1, value));
	else
		return (advanced_binary_helper(array + i + 1, size - i - 1, value));
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
