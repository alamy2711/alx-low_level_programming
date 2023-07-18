#include "stdio.h"

/**
 * main - Entry point
 * A program that cprints the first 98 Fibonacci numbers,
 * starting with 1 and 2, followed by a new line.
 * Return: Always 0 (Success)
*/
int main(void)
{
	int i;
	long double x = 1, y = 2, f;

	for (i = 1; i <= 98; i++)
	{
		if (i <= 2)
			printf("%d", i);
		else
		{
			f = x + y;
			x = y;
			y = f;
			printf("%.0Lf", f);
		}

		if (i != 98)
			printf(", ");
	}
	printf("\n");

	return (0);
}
