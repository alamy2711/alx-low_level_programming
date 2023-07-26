#include "main.h"

/**
 * _strncat - concatenates two strings using n bytes from src
 * @dest: string to append to
 * @src: string to append
 * @n: number of bytes to append
 * Return: pointer to the resulting string dest
*/
char *_strncat(char *dest, char *src, int n)
{
	int i = 0, dest_len = 0;

	while (dest[dest_len] != '\0')
		dest_len++;

	while (i++ < n && src[i - 1] != '\0')
		dest[dest_len + i - 1] = src[i - 1];

	dest[dest_len + i - 1] = '\0';

	return (dest);
}
