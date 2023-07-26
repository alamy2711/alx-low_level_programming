#include "main.h"

/**
 * reverse_array - reverses the content of an array of integers
 * @a: array to reverse
 * @n: array's length
 * Return: void
*/
void reverse_array(int *a, int n)
{
	int i, tmp;

	for (i = 0; i < n / 2; i++)
	{
		tmp = a[i];
		a[i] = a[n - 1 - i];
		a[n - 1 - i] = tmp;
	}
}
