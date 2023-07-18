#include "main.h"

/**
 * times_table - prints the 9 times table, starting with 0.
 *
 * Return: void
 */
void times_table(void)
{
	int m;
	int i, j;

	for (i = 0; i <= 9; i++)
	{
		for (j = 0; j <= 9; j++)
		{
			m = i * j;

			if (j == 0)
				_putchar(m + '0');
			else if (m >= 10)
			{
				_putchar(m / 10 + '0');
				_putchar(m % 10 + '0');
			}
			else if (m < 10)
				_putchar(m % 10 + '0');

			if (j != 9 && (m + i) < 10)
			{
				_putchar(',');
				_putchar(' ');
				_putchar(' ');
			}
			else if (j != 9 && (m + i) >= 10)
			{
				_putchar(',');
				_putchar(' ');
			}
		}
		_putchar('\n');
	}
}
