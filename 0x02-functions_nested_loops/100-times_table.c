#include "main.h"

/* Prototypes */
void print_separator(int i, int j, int n, int m);

/**
 * print_times_table - prints the n times table, starting with 0.
 * @n: the table size
 *
 * Return: void
 */
void print_times_table(int n)
{
	int i, j, m;

	if (n >= 0 && n <= 15)
	{
		for (i = 0; i <= n; i++)
		{
			for (j = 0; j <= n; j++)
			{
				m = i * j;
				if (j == 0)
					_putchar(m + '0');
				else if (m >= 100)
				{
					_putchar(m / 100 + '0');
					_putchar((m / 10) % 10 + '0');
					_putchar(m % 10 + '0');
				}
				else if (m < 100 && m >= 10)
				{
					_putchar(m / 10 + '0');
					_putchar(m % 10 + '0');
				}
				else if (m < 10)
					_putchar(m % 10 + '0');
				print_separator(i, j, n, m);
			}
			_putchar('\n');
		}
	}
}

/**
 * print_separator - prints separators between times table cells
 * @i: row multiplier
 * @j: column multiplier
 * @n: the table size
 * @m: product m = i * j
 *
 * Return: void
 */
void print_separator(int i, int j, int n, int m)
{
	if (j != n && (m + i) < 10)
	{
		_putchar(',');
		_putchar(' ');
		_putchar(' ');
		_putchar(' ');
	}
	else if (j != n && (m + i) >= 10 && (m + i) < 100)
	{
		_putchar(',');
		_putchar(' ');
		_putchar(' ');
	}
	else if (j != n && (m + i) >= 100)
	{
		_putchar(',');
		_putchar(' ');
	}
}
