#include "stdio.h"

/**
 * main - Entry point
 * A program that cprints the first 50 Fibonacci numbers,
 * starting with 1 and 2, followed by a new line.
 * Return: Always 0 (Success)
*/
int main(void)
{
	long x = 1, y = 2, f, sum = 2;

	do {
		f = x + y;
		x = y;
		y = f;
		if ((f % 2) == 0)
			sum += f;
	} while (f < 4000000);

	printf("\n");

	return (0);
}
