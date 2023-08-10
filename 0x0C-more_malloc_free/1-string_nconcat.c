#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * string_nconcat - concatenates two strings
 * @s1: string to concatenate to
 * @s2: string to concatenate
 * @n: number of bytes to concatenate
 * Return: new concatenated string, and returns NULL if it fails
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *new_str;
	unsigned int i, bytes;

	if (s1 == NULL)
		s1 = "\0";
	if (s2 == NULL)
		s2 = "\0";

	if (n >= strlen(s2))
		bytes = strlen(s2);
	else
		bytes = n;

	new_str = malloc((strlen(s1) + bytes + 1) * sizeof(char));

	if (new_str == NULL)
		return (NULL);

	for (i = 0; i < strlen(s1); i++)
		new_str[i] = s1[i];

	for (i = 0; i < bytes; i++)
		new_str[strlen(s1) + i] = s2[i];

	new_str[strlen(s1) + bytes] = '\0';

	return (new_str);
}
