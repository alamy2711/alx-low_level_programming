#include "main.h"

/**
 * _strncpy - copies a string using n bytes from src
 * @dest: string to copy to
 * @src: string to copy from
 * @n: number of bytes to copy
 * Return: pointer to the resulting string dest
*/
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0, src_len = 0;

	while (src[src_len] != '\0')
		src_len++;

	while (i++ < n)
		dest[i - 1] = src[i - 1];

	while (src_len + 1 < n)
		dest[1 + src_len++] = '\0';

	return (dest);
}
