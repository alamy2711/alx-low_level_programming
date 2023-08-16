#include "function_pointers.h"
#include <stdio.h>

/**
 * print_elem - prints an integer
 * @elem: integer to print
 *
 * Return: void
 */
void print_elem(int elem)
{
	printf("%d\n", elem);
}

/**
 * print_elem_hex - prints an integer in hexadecimal
 * @elem: integer to print
 *
 * Return: void
 */
void print_elem_hex(int elem)
{
	printf("0x%x\n", elem);
}

/**
 * main - check the code
 * Return: Always 0.
 */
int main(void)
{
	int array[5] = {0, 98, 402, 1024, 4096};

	array_iterator(array, 5, print_elem);
	printf("\n");
	array_iterator(array, 5, print_elem_hex);
	return (0);
}