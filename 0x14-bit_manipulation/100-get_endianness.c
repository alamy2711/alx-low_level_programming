#include "main.h"

/**
 * get_endianness - Checks the endianness
 *
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	int n = 0x02cccc01;
	char *p = (char *)&n;

	if (*p == 1 && *(p + 3) == 2)
		return (1);

	return (0);
}
