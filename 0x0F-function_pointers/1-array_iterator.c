#include "function_pointers.h"

/**
 * array_iterator - Executes a function given as a parameter
 * on each element of an array
 * @array: Array of elements
 * @size: Array's size
 * @action: Function to execute
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i;

	if (array != NULL && action != NULL)
	{
	for (i = 0; i < size; i++)
		action(array[i]);
	}
}
