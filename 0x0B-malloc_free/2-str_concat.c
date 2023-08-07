#include <stdlib.h>

/**
 * str_concat - concatenates two strings
 * @s1: string to concatenate to
 * @s2: string to concatenate
 * Return: NULL if malloc failed, otherwise returns concatenated string
 */
char *str_concat(char *s1, char *s2)
{
	char *new_str;
	int i, len1 = 0, len2 = 0;

	/* Calculate length of s1 and s2 */
	if (s1 != NULL)
		for (i = 0; s1[i] != 0; i++)
			len1++;

	if (s2 != NULL)
		for (i = 0; s2[i] != 0; i++)
			len2++;

	new_str = malloc((len1 + len2 + 1) * sizeof(char));

	if (new_str == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		new_str[i] = s1[i];

	for (i = 0; i < len2; i++)
		new_str[len1 + i] = s2[i];

	new_str[len1 + len2] = '\0';

	return (new_str);
}
