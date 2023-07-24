#include <stdio.h>
#include "main.h"

/**
 * _atoi - convert a string to an integer
 * @s: string to convert
 * Return: converted string
*/
int _atoi(char *s)
{
	int i, res = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
			res = (res * 10) + (s[i] - '0');
	}

	return (res);
}
