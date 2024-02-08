#include "search_algos.h"

/**
 * interpolation_search - Search for a value in a sorted array using
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
	size_t position, down, up;

	position = 0;
	down = 0;
	up = size - 1;

	if (array == NULL || size == NULL)
		return (-1);

	while (1)
	{
		position = down + (((double)(up - down) / (
			array[up] - array[down])) * (value - array[down]));

		if (size <= position)
		{
			printf("Value checked array[%lu] is out of range\n", position);
			break;
		}

		printf("Value checked array[%lu] = [%d]\n", position, array[position]);

		if (value == array[position])
			return (position);
		else if (value < array[position])
			up = position - 1;
		else
			down = position + 1;
	}

	return (-1);
}
