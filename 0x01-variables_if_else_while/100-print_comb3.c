#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	int x, y;

	for (x = 0; x <= 8; x++)
	{
		for (y = x + 1; y <= 9; y++)
		{
			putchar(x + '0');
			putchar(y + '0');
			if (x != 8 || y != 9)
			{
				putchar(',');
				putchar(' ');
			};
		};
	};
	putchar('\n');

	return (0);
}
