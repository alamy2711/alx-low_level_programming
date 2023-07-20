#include "main.h"

/**
 * print_number - prints an integer
 * @n: number to print
 * Return: void
*/
void print_number(int n)
{
	unsigned int holder;

	if (n < 0)
	{
		holder = -n;
		_putchar('-');
	}
	else
		holder = n;

	if (holder / 10 != 0)
		print_number(holder / 10);

	_putchar((holder % 10) + '0');
}
