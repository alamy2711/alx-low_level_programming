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
	const int MAX_SUM = 2772;
	char passwd[87];
	int j, i = 0, passwd_sum = 0;

	/* Setting Seed */
	srand(time(0));

	while (passwd_sum < MAX_SUM)
	{
		int r = getRandom(32, 126);

		if (passwd_sum + r < MAX_SUM - 32 || passwd_sum + r == MAX_SUM)
		{
			passwd[i] = r;
			passwd_sum += r;
			i++;
		}
	}

	for (j = 0; j < i; j++)
		putchar(passwd[j]);

	return (0);
}

/**
 * getRandom - gets a random integer in a specific range
 * @start: range's start
 * @end: range's end
 * Return: a random integer from @start to @end
*/
int getRandom(int start, int end)
{
	return (rand() % (end + 1 - start) + start);
}
