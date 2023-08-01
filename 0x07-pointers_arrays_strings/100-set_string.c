#include "main.h"
#include <stdio.h>
/**
 * set_string - sets the value of a pointer to a char
 * @s: string to set to
 * @to: string sat to
 * Return: void
*/
void set_string(char **s, char *to)
{
	*s = to;
}
