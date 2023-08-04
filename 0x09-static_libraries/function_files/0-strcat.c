#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: string to append to
 * @src: string to append
 * Return: pointer to the resulting string dest
*/
char *_strcat(char *dest, char *src)
{
	int i = 0, dest_len = 0;

	while (dest[dest_len] != '\0')
		dest_len++;

	while (src[i++] != '\0')
		dest[dest_len + i - 1] = src[i - 1];

	dest[dest_len + i - 1] = '\0';

	return (dest);
}
