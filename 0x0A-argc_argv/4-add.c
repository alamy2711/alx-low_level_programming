#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * main - A program that adds positive numbers
 * @argc: arguments count
 * @argv: arguments vector
 * Return: 1 if a no-digit was passed as an argument, otherwise 0
*/
int main(int argc, char *argv[])
{
	int i, j, sum = 0;

	for (i = 1; i < argc; i++)
	{
		for (j = 0; argv[i][j] != '\0'; j++)
		{
			if (!isdigit(argv[i][j]))
			{
				printf("Error\n");
				return (1);
			}
		}
		sum += atoi(argv[i]);
	}
	printf("%d\n", sum);

	return (0);
}
