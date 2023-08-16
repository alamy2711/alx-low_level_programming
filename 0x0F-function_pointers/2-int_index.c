#include "function_pointers.h"

/**
 * int_index - Searches for an integer
 * @array: Array to search
 * @size: Array's size
 * @cmp: Function that compares values
 *
 * Return: Index of the first element that has been found
 * otherwise -1 if no element matches
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array != NULL && cmp != NULL)
	{
		for (i = 0; i < size; i++)
		{
			if (cmp(array[i]))
				return (i);
		}
	}

	return (-1);
}
