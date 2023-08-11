#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

/* Prototype */
void print_error_and_exit(void);
void print_reversed_string(char *str);

/**
 * main - A program that multiplies two positive numbers
 * @ac: Arguments count
 * @av: Arguments vector
 *
 * Return: Always 0 (Sucess)
 */
int main(int ac, char *av[])
{
	char *num1, *num2;
	char *res;
	int len1, len2;
	int i, j, k, dig1, dig2, sum, carry;

	/* Checks if number of arguments is incorrect */
	if (ac != 3)
		print_error_and_exit();

	num1 = av[1];
	num2 = av[2];
	len1 = strlen(num1);
	len2 = strlen(num2);

	/* Allcoate a block of memory to store the result */
	res = malloc((len1 + len2 + 1) * sizeof(char));
	if (res == NULL)
		print_error_and_exit();

	/* Initialize res with zeros */
	for (i = 0; i < len1 + len2 + 1; i++)
		res[i] = '0';

	/* Calcualate Multiplication */
	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;

		for (j = len2 - 1; j >= 0; j--)
		{
			/* Checks if num1 and num2 contains no-digit characters*/
			if (!isdigit(num1[i]) || !isdigit(num2[j]))
			{
				free(res);
				print_error_and_exit();
			}

			dig1 = num1[i] - '0';
			dig2 = num2[j] - '0';

			k = (len1 - i - 1) + (len2 - j - 1);
			sum = dig1 * dig2 + (res[k] - '0') + carry;

			carry = sum / 10;

			res[k] = (sum % 10) + '0';
		}
		if (carry > 0)
		{
			k = (len1 - i - 1) + (len2 - j - 1);
			res[k] += carry;
		}
	}

	/* Skip zeros from the right */
	for (i = len1 + len2 - 1; i >= 0 && res[i] == '0';)
		i--;

	/* Checks if result is 0 */
	if (i == -1)
	{
		_putchar('0');
		_putchar('\n');
		free(res);
		return (0);
	}

	res[i + 1] = '\0';

	/* Print the reversed result */
	print_reversed_string(res);

	free(res);

	return (0);
}

/**
 * print_error_and_exit - Prints error message and exits with a status of 98
 */
void print_error_and_exit(void)
{
	char *error_msg = "Error\n";
	unsigned int i;

	for (i = 0; i < strlen(error_msg); i++)
		_putchar(error_msg[i]);

	exit(98);
}

/**
 * print_reversed_string - Prints a string in reverse
 * @str: String to print in reverse
 */
void print_reversed_string(char *str)
{
	int i;

	for (i = strlen(str) - 1; i >= 0; i--)
		_putchar(str[i]);

	_putchar('\n');
}
