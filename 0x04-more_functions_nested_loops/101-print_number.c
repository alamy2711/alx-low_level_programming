#include "main.h"

/**
 * print_number - prints an integer
 * @n: number to print
 * Return: void
*/
void print_number(int n)
{
	int l, holder;

	l = 1;
	holder = n;


	if (n < 0)
	{
		n *= -1;
		_putchar('-');
	}

	do {
		holder /= 10;
		l *= 10;
	} while (holder != 0);

	l /= 10;

	while (l != 0)
	{
		_putchar((n / l) % 10 + '0');
		l /= 10;
	}
}
