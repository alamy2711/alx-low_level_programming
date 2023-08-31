#include "main.h"

/**
 * flip_bits - Gets the number of bits you would need to flip to get
 * from one number to another
 * @n: Number one
 * @m: number two
 *
 * Return: The number of bits you would need to flip to get
 * from one number to another.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int numOfBits = sizeof(unsigned long int) * 8;
	unsigned int i, mask_n, mask_m, flippedBits = 0;

	for (i = 0; i < numOfBits; i++)
	{
		mask_n = (n >> (numOfBits - 1 - i)) & 1;
		mask_m = (m >> (numOfBits - 1 - i)) & 1;

		if (mask_n != mask_m)
			flippedBits++;
	}

	return (flippedBits);
}
