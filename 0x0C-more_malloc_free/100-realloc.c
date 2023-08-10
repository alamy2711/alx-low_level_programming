#include "main.h"
#include <stdlib.h>

/**
 * _realloc - Reallocates a memory block using malloc and free
 * @ptr: Pointer to a previously allcoated memory
 * @old_size: Size of allocated memory for ptr
 * @new_size: New size of memory to reallocate
 *
 * Return: Pointer to the new reallocated memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(new_size);

	if (new_ptr == NULL)
		return (NULL);

	if (ptr == NULL)
		return (new_ptr);

	for (i = 0; i < new_size; i++)
	{
		if (i == old_size)
			break;
		new_ptr[i] = ((char *)ptr)[i];
	}
	free(ptr);

	return (new_ptr);
}
