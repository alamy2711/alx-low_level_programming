#include "main.h"

/**
 * print_number - prints an integer
 * @n: number to print
 * Return: void
*/
void print_number(int n)
{
	unsigned int l, holder, pr;

	l = 1;

	if (n < 0)
	{
		n *= -1;
		_putchar('-');
	}
	holder = n;

	do {
		holder /= 10;
		l *= 10;
	} while (holder != 0);
	l /= 10;

	pr = n;

	while (l != 0)
	{
		_putchar((pr / l) % 10 + '0');
		l /= 10;
	}
}

