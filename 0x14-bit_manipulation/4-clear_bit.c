#include "main.h"

/**
 * clear_bit - Sets the value of a bit to 0 at a given index
 * @n: The number to set its index value to 0
 * @index: The index
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int numOfBits = sizeof(unsigned long int) * 8;

	if (index >= numOfBits)
		return (-1);

	*n &= (~(1 << index));

	return (1);
}
