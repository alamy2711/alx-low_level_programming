#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

/* Prototype */
void print_error_and_exit(void);
void print_reversed_array(int *arr, int len);

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
	int *res;
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
	res = malloc((len1 + len2) * sizeof(int));
	if (res == NULL)
		print_error_and_exit();

	/* Initialize res with zeros */
	for (i = 0; i < len1 + len2 + 1; i++)
		res[i] = 0;

	/* Calcualate Multiplication */
	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;

		for (j = len2 - 1; j >= 0; j--)
		{
			/* Checks if num1 and num2 contains no-digit characters*/
			if (!isdigit(num1[i]) || !isdigit(num2[j]))
				print_error_and_exit();

			dig1 = num1[i] - '0';
			dig2 = num2[j] - '0';

			k = (len1 - i - 1) + (len2 - j - 1);
			sum = dig1 * dig2 + res[k] + carry;

			carry = sum / 10;

			res[k] = (sum % 10);
		}
		if (carry > 0)
		{
			k = (len1 - i - 1) + (len2 - j - 1);
			res[k] += carry;
		}
	}

	/* Skip zeros from the right */
	for (i = len1 + len2 - 1; res[i] == 0 && i >= 0;)
		i--;

	/* Checks if result is 0 */
	if (i == -1)
	{
		_putchar('0');
		_putchar('\n');
		return (0);
	}

	/* Print the reversed result */
	print_reversed_array(res, i + 1);

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
 * print_reversed_array - Prints an array in reverse
 * @arr: String to print in reverse
 * @len: Array length
 */
void print_reversed_array(int *arr, int len)
{
	int i;

	for (i = len - 1; i >= 0; i--)
		_putchar(arr[i] + '0');

	_putchar('\n');
}
