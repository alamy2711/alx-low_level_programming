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
	return ((n >> index) & 1);
}
