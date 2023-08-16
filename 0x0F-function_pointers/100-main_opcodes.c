#include <stdio.h>
#include <stdlib.h>

/**
 * main - A program that prints the opcodes of its own main function
 * @ac: Arguments count
 * @av: Arguments vector
 *
 * Return: 0 (Success)
 */
int main(int ac, char *av[])
{
	int i, bytes;
	int (*main_ptr)(int, char **);

	/* Checks number of Arguments */
	if (ac != 2)
	{
		printf("Error\n");
		exit(1);
	}

	/* Checks number of bytes */
	bytes = atoi(av[1]);
	if (bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	/* Printing opcode */
	main_ptr = main;
	for (i = 0; i < bytes; i++)
	{
		printf("%02x", *((unsigned char *)main_ptr++));
		if (i != bytes - 1)
			printf(" ");
	}
	printf("\n");

	return (0);
}
