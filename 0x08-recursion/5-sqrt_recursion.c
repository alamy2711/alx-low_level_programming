#include "main.h"

/**
 * _sqrt - calculate square root of integer using supposions
 * @n: number to calculate its square root
 * @sup: supposed number
 * Return: square root of n
*/
int _sqrt(int n, int sup)
{
	if (sup > 2 * n)
		return (-1);
	if (n == sup * sup)
		return (sup);

	return (_sqrt(n, sup + 1));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number
 * Return: square root of the number n
*/
int _sqrt_recursion(int n)
{
	return (_sqrt(n, 0));
}
