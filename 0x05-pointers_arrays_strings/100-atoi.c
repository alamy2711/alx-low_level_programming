#include <stdio.h>
#include "main.h"

/**
 * _atoi - convert a string to an integer
 * @s: string to convert
 * Return: converted string
*/
int _atoi(char *s)
{
	unsigned int i, sign = 0, res = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '-')
			sign++;

		if (s[i] >= '0' && s[i] <= '9')
		{
			res = (res * 10) + (s[i] - '0');

			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
		}
	}

	if (sign % 2 == 1)
		return (-res);

	return (res);
}
