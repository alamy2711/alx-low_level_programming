#include "main.h"

/**
 * swap_int - swaps the values of two integers
 * @a: pointer to swap the value it points to
 * @b: pointer to swap the value it points to
 * Return: void
*/
void swap_int(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}
