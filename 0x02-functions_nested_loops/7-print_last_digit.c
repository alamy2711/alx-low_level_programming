#include <stdlib.h>
#include "main.h"

/**
 * print_last_digit - prints the last digit of a number.
 * @n: the number to print its last digit
 *
 * Return: The value of the last digit
 */
int print_last_digit(int n)
{
	int lastDigit;

	lastDigit = abs(n % 10);
	_putchar(lastDigit + '0');

	return (lastDigit);
}
