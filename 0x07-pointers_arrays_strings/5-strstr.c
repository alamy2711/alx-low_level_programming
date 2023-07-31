#include "main.h"
#include <stddef.h>

/**
 * _strstr - locates a substring
 * @haystack: string to be scanned
 * @needle: string to be searched with-in haystack
 * Return: pointer to the beginning of the located substring
 * or NULL if the substring is not found
*/
char *_strstr(char *haystack, char *needle)
{
	int i, j = 0;

	if (needle[j] == '\0')
		return (haystack);

	for (i = 0; haystack[i] != '\0'; i++)
	{
		if (haystack[i] == needle[j])
		{
			for (j = 1; needle[j] != '\0'; j++)
			{
				if (haystack[i + j] != needle[j])
				{
					j = 0;
					break;
				}
			}
			if (needle[j] == '\0')
				return (haystack + i);
		}
	}
	return (NULL);
}
