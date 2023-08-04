#include "main.h"

/**
 * _strlen - determine the length of a string
 * @s: pointer to determine the value it points to
 * Return: length of *n
*/
int _strlen(char *s)
{
	int i, len;

	len = 0;

	for (i = 0; s[i] != '\0'; i++)
		len++;

	return (len);
}
