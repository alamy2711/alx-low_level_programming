#include "3-calc.h"

/**
 * main - A program that performs simple operations
 * @ac: Arguments count
 * @av: Arguments vector
 *
 * Return: 0 (Success)
 */
int main(int ac, char *av[])
{
	int num1, num2, result;
	char *op;

	/* Checks arguments count */
	if (ac != 4)
	{
		printf("Error\n");
		exit(98);
	}

	op = av[2];
	num1 = atoi(av[1]);
	num2 = atoi(av[3]);

	/* Checks if the operator given is correct */
	get_op_func(op);
	if (get_op_func(op) == NULL)
	{
		printf("Error\n");
		exit(99);
	}

	result = get_op_func(op)(num1, num2);

	printf("%d\n", result);

	return (0);
}
