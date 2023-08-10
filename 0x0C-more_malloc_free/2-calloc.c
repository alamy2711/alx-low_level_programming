#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * _calloc - allocates memory for an array using malloc
 * @nmemb: number of elements to allocate
 * @size: size of each element
 * Return: pointer to the allocated memory, and returns NULL if nmemb or size
 * is 0 or if it failes
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *arr;

	arr = malloc(nmemb * size);

	if (arr == NULL || nmemb == 0 || size == 0)
		return (NULL);

	memset(arr, 0, nmemb * size);

	return (arr);
}
