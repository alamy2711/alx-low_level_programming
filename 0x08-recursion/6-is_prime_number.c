#include "main.h"

/**
 * isPrime - checks if a number is a prime
 * @n: number to check
 * @tester: tester number
 * Return: 1 if the input integer is a prime, otherwise 0
*/
int isPrime(int n, int tester)
{
	if (tester > n / 2)
		return (1);
	if (n % tester == 0 || n % (tester + 2) == 0)
		return (0);

	return (isPrime(n, tester + 6));
}

/**
 * is_prime_number - checks if a number is a prime
 * @n: number to check
 * Return: 1 if the input integer is a prime, otherwise 0
*/
int is_prime_number(int n)
{
	if (n < 2)
		return (0);
	if (n < 4)
		return (1);
	if (n % 2 == 0 || n % 3 == 0)
		return (0);

	return (isPrime(n, 5));
}
