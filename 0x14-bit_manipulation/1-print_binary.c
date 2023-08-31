#include "main.h"

/**
 * print_binary - Prints the binary representation of a number
 * @n: The number to print in binary
 */
void print_binary(unsigned long int n)
{
	const int numOfBits = sizeof(unsigned long int) * 8;
	unsigned long int mask;
	int i, zeroSkipper = 0;

	for (i = 0; i < numOfBits; i++)
	{
		mask = (n >> (numOfBits - 1 - i)) & 1;

		if (mask == 1)
		{
			_putchar('1');
			zeroSkipper = 1;
		}

		if (mask == 0 && (zeroSkipper == 1 || i == numOfBits - 1))
			_putchar('0');
	}
}
