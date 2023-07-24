#include <string.h>
#include "main.h"

/**
 * rev_string - reverses a string
 * @s: pointer to reverses the string it points to
 * Return: void
*/
void rev_string(char *s)
{
	int i, len;
	char ch;

	len = strlen(s);

	for (i = 0; i < len / 2; i++)
	{
		ch = s[len - 1 - i];
		s[len - 1 - i] = s[i];
		s[i] = ch;
	}
}
