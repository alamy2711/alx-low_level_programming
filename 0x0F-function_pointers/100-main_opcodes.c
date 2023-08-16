#include <stdio.h>
#include <stdlib.h>

/**
 * main - A program that prints the opcodes of its own main function
 */
int main (int ac, char *av[])
{
	int i, bytes;
	int (*main_ptr)(int, char **);

	if (ac != 2)
	{
		printf("Error\n");
		exit(1);
	}

	bytes = atoi(av[1]);
	if (bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	main_ptr = main;

	for (i = 0; i < bytes; i++)
	{
		printf("%02x", *((unsigned char *)main_ptr++));
		if (i != bytes - 1)
			printf(" ");
	}
	printf ("\n");

	return (0);
}
