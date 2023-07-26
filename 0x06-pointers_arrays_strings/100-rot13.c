#include "main.h"

/**
 * rot13 - encodes a string using rot13
 * @s: string to encodes
 * Return: encoded string
*/
char *rot13(char *s)
{
	char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot13[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int i, j;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; j < 26 * 2; j++)
		{
			if (s[i] == chars[j])
			{
				s[i] = rot13[j];
				break;
			}
		}
	}
	return (s);
}
