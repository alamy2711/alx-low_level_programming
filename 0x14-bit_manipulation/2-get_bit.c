#include "main.h"

/**
 * get_bit - Gets the value of a bit at a given index
 * @n: The number to get the value from
 * @index: The index
 *
 * Return: The value of a bit at a given index
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int numOfBits = sizeof(unsigned long int) * 8;

	if (index >= numOfBits || index < numOfBits)
		return (-1);

	return ((n >> index) & 1);
}
