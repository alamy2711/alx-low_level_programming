#include "main.h"

/**
 * skip_wildcard - skips wildcard in a string
 * @str: string
 * Return: void
*/
void skip_wildcard(char *str)
{
	if (*(str + 1) != '*')
		return;
	skip_wildcard(++str);
}

/**
 * wildcmp - compares two strings considering wildcard
 * @s1: string to compare
 * @s2: string to compare, can contain wildcard
 * Return: 1 if the strings can be considered identical, otherwise return 0
*/
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	if (*s2 == '*' && *(s2 + 1) == '*')
		skip_wildcard(s2);

	if (*s2 == '*' && *(s2 + 1) != '\0' && *s1 == '\0')
		return (0);

	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	if (*s2 == '*')
		return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));

	return (0);
}
