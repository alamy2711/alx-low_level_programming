#include <stdlib.h>

/**
 * _strdup - duplicates a string
 * a specific char
 * @str: string to duplicate
 * Return: NULL if str = NULL or malloc failed, otherwise returns copy of str
 */
char *_strdup(char *str)
{
	char *s;
	int i, len = 0;

	if (str == NULL)
		return (NULL);

	/* Calculate str's length */
	for (i = 0; str[i] != '\0'; i++)
		len++;

	s = malloc(len * sizeof(char) + 1);

	if (s == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		s[i] = str[i];

	s[len] = '\0';

	return (s);
}
