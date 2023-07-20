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
	unsigned long i, N = 612852475143;

	for (i = 2; i * i <= N; i++)
		while (N % i == 0)
			N /= i;
	printf("%lu\n", N);

	return (0);
}

