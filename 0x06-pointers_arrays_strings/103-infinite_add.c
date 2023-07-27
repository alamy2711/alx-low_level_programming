#include "main.h"

/* Prototype */
int _strlen(char *s);

/**
 * infinite_add - adds two numbers
 * @n1: number to add
 * @n2: number to add
 * @r: buffer to store the result
 * @size_r: buffer size
 * Return: pointer to the result
*/
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i = _strlen(n1) - 1;
	int j = _strlen(n2) - 1;
	int k = size_r - 2;
	int hold = 0;

	while (i >= 0 || j >= 0 || hold)
	{
		int sum = hold;

		if (i >= 0)
			sum += n1[i--] - '0';
		if (j >= 0)
			sum += n2[j--] - '0';
		if (k >= 0)
			r[k--] = sum % 10 + '0';
		else
			return (0);
		hold = sum / 10;
	}

	for (i = 0, j = 0; i < size_r; i++)
	{
		if (r[i] >= '0' && r[i] <= '9')
		{
			r[j] = r[i];
			j++;
		}
	}


	r[j] = '\0';

	return (r);
}

/**
 * _strlen - determine the length of a string
 * @s: pointer to determine the value it points to
 * Return: length of *n
*/
int _strlen(char *s)
{
	int i, len;

	len = 0;

	for (i = 0; s[i] != '\0'; i++)
		len++;

	return (len);
}
