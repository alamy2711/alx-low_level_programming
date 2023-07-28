#include "main.h"
#include <stdio.h>

/**
* print_buffer - prints a buffer
* @b: buffer to print
* @size: buffer's size
* Return: void
*/
void print_buffer(char *b, int size)
{
	int i, j = 0, loop;

	if (size % 10 != 0)
		loop = size + (10 - size % 10);
	else
		loop = size;

	for (i = 0; i <= loop; i++)
	{
		if (i % 10 == 0 && i != 0)
		{
			printf(" ");
			for (; j < i && j < size; j++)
			{
				if (b[j] >= 32 && b[j] <= 126)
					putchar(b[j]);
				else
					printf(".");
			}
			printf("\n");
		}
		if (i % 2 == 0 && i % 10 != 0)
			printf(" ");

		if (i % 10 == 0 && i < loop)
			printf("%08x: ", i);

		if (i < size)
			printf("%02x", b[i]);

		if (i >= size && i < loop)
			printf("  ");
	}
}
