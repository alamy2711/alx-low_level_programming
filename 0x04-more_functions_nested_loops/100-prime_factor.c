#include <stdio.h>
#include <math.h>

/* Prototype */
int isPrime(int num);

/**
 * main - finds and prints the largest prime factor of the number 612852475143
 *
 * Return: Always 0 (Success)
*/
int main(void)
{
	const unsigned long int NUM = 612852475143;
	unsigned long int i, lp;

	for (i = 2; i <= NUM; i++)
	{
		if (isPrime(i) && NUM % i == 0)
		{
			lp = i;
			/*printf("%lu\n", lp);*/
		}
	}
	printf("%lu\n", lp);

	return (0);
}

/**
 * isPrime - checks if a number is prime
 * @n: number to check
 * Return: 1 if n is prime, 0 if n is not prime
*/
int isPrime(int n)
{
	int i;

	if (n <= 1)
		return (0);
	if (n <= 3)
		return (1);

	if (n % 2 == 0 || n % 3 == 0)
		return (0);

	for (i = 5; i * i <= n; i = i + 6)
	{
		if (n % i == 0 || n % (i + 2) == 0)
			return (0);
	}

	return (1);
}
