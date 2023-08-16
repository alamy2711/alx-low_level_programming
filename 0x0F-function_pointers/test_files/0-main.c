#include "function_pointers.h"
#include <stdio.h>

/**
 * print_name_as_is - prints a name as is
 * @name: name to print
 *
 * Return: void
 */
void print_name_as_is(char *name)
{
	printf("Hello, my name is %s\n", name);
}

/**
 * print_name_uppercase - prints a name in uppercase
 * @name: name to print
 *
 * Return: void
 */
void print_name_uppercase(char *name)
{
	int i;

	printf("Hello, my uppercase name is ");
	for (i = 0; name[i]; i++)
	{
		if (name[i] >= 'a' && name[i] <= 'z')
			printf("%c", name[i] - 32);
		else
			printf("%c", name[i]);
	}
	printf("\n");
}

/**
 * main - check the code
 * Return: Always 0.
 */
int main(void)
{
	print_name("Bob", print_name_as_is);
	print_name("Bob Dylan", print_name_uppercase);
	printf("\n");
	return (0);
}