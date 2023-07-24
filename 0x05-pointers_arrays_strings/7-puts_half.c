#include <string.h>
#include "main.h"

/**
 * puts_half - prints half of a string, followed by a new line
 * @str: pointer to the string given
 * Return: void
*/
void puts_half(char *str)
{
	int i, len, n;

	len = strlen(str);

	if (len % 2 == 1)
		n = (len - 1) / 2;
	else
		n = len / 2;

	for (i = len - n; i < len; i++)
		_putchar(str[i]);
	_putchar('\n');
}
