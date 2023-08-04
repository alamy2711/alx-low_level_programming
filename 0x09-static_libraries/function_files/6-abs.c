#include "main.h"

/**
 * _abs  - computes the absolute value of an integer.
 * @n: the character to compute
 *
 * Return: The absolute value of an integer.
 */
int _abs(int n)
{
	if (n > 0)
		return (n);
	else if (n < 0)
		return (-n);
	else
		return (0);
}
