#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @s: string to capitalize its words
 * Return: capitalized string
*/
char *cap_string(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z' && (s[i - 1] == 9 || s[i - 1] == 10 ||
		s[i - 1] == 32 || s[i - 1] == 33 || s[i - 1] == 34 || s[i - 1] == 40 ||
		s[i - 1] == 41 || s[i - 1] == 44 || s[i - 1] == 46 || s[i - 1] == 59 ||
		s[i - 1] == 63 || s[i - 1] == 123 || s[i - 1] == 125 || i == 0))
			s[i] -= 32;
	}
	return (s);
}
