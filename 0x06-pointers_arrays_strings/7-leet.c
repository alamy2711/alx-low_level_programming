#include "main.h"

/**
 * leet - encodes a string into 1337
 * @s: string to encodes
 * Return: encoded string
*/
char *leet(char *s)
{
	char leet_chars[] = "AaEeOoTtLl";
	char leet_nums[] = "4433007711";
	int i, j;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (s[i] == leet_chars[j])
			{
				s[i] = leet_nums[j];
				break;
			}
		}
	}
	return (s);
}
