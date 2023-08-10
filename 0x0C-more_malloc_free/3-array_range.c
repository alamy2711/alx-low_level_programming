#include "main.h"
#include <stdlib.h>

/**
 * array_range - creates an array of integers
 * @min: minimum integer
 * @max: maximum integer
 * Return: pointer to the newly created array, and returns NULL if min > max
 * or if it fails
 */
int *array_range(int min, int max)
{
	int *arr, i, size;

	size = max - min + 1;

	if (size <= 0)
		return (NULL);

	arr = malloc(size * sizeof(int));

	if (arr == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		arr[i] = min + i;

	return (arr);
}
