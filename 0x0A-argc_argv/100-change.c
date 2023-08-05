#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * main - A program that prints the minimum number of coins
 * to make change for an amount of money
 * @argc: arguments count
 * @argv: arguments vector
 * Return: 1 if argc != 2, otherwise 0
*/
int main(int argc, char *argv[])
{
	int i, amt, coins = 0;
	int coins_values[5] = {25, 10, 5, 2, 1};

	if (argc != 2)
	{
		printf("Error\n");
		return (0);
	}

	amt = atoi(argv[1]);

	for (i = 0; i < 5; i++)
	{
		if (amt >= coins_values[i])
		{
			coins += amt / coins_values[i];
			amt %= coins_values[i] * (amt / coins_values[i]);
		}
	}
	printf("%d\n", coins);

	return (0);
}
