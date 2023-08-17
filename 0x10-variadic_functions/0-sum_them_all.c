#include "variadic_functions.h"

/**
 * sum_them_all - Calculates the sum of all the given parameters
 * @n: Number of arguments to calculate their sum
 *
 * Return: Sum of all the given numbers
 */
int sum_them_all(const unsigned int n, ...)
{
	unsigned int i;
	int sum = 0;
	va_list args;

	if (n == 0)
		return (0);

	va_start(args, n);

	for (i = 0; i < n; i++)
		sum += va_arg(args, int);

	va_end(args);

	return (sum);
}
