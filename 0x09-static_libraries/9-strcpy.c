#include "main.h"

/**
 * _strcpy - copies the string from a string to another
 * @dest: string to copy to
 * @src: string to copy from
 * Return: pointer to dest
*/
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = src[i];

	return (dest);
}
