#include "main.h"

/**
 * print_number - prints an integer
 * @n: integer to print
 * Return: void
*/
void print_number(int n)
{
	int i, mag = 1, tmp = n;

	if (n < 0)
	{
		n *= -1;
		tmp = n;
		_putchar('-');
	}

	while (tmp >= 10)
	{
		tmp /= 10;
		mag *= 10;
	}

	for (i = 1; i <= mag; i *= 10)
		_putchar((n / (mag / i)) % 10 + '0');
}
