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
 * @num: number to check
 * Return: 1 if num is prime, 0 if num is not prime
*/
int isPrime(int num)
{
	int i, isPrime = 1;

	if (num <= 0)
	{
		return (0);
	}
	if (num == 1)
	{
		return (0);
	}
	for (i = 2; i <= sqrt(num); ++i)
	{
		if (num % i == 0)
		{
			isPrime = 0;
		}
	}

	return (isPrime);
}
