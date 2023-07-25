#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/* Prototype */
int getRandom(int start, int end);

/**
 * main - Program that generates random valid passwords
 * for the program 101-crackme
 * Return: Always 0 (Success)
*/
int main(void)
{
	int sum = 0;

	srand(time(0));

	while (sum < 2772)
	{
		int r = rand() % 95 + 32;

		if (sum + r < 2740 || sum + r == 2772)
		{
			putchar(r);
			sum += r;
		}
	}

	return (0);
}

