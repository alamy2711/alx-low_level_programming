#include "search_algos.h"

/**
 * interpolation_search - Searches for a value in a sorted array using
 * interpolation search.
 *
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: Value to search for.
 *
 * Return: Index of the value in the array if found, otherwise -1.
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t left, right, pos;

	if (array == NULL)
		return (-1);

	for (left = 0, (right = size - 1); right >= left;)
	{
		/* Calculate the probable position */
		pos = left + (((double)(right - left) / (
			array[right] - array[left])) * (value - array[left]));

		/* If pos is within the array */
		if (pos < size)
			printf("Value checked array [%ld] = [%d]\n", pos, array[pos]);
		else
		{
			printf("Value checked array [%ld] is out of range\n", pos);
			break;
		}

		/* If value is found at pos */
		if (array[pos] == value)
			return (pos);
		/* If value is smaller, search in left subarray */
		if (array[pos] > value)
			right = pos - 1;
		/* If value is larger, search in right subarray */
		else
			left = pos + 1;
	}

	return (-1);
}
