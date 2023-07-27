#include "main.h"

/**
* print_buffer - prints a buffer
 * @b: the address of the memory to print
 * @size: the size of the memory to print
 */
void print_buffer(char *b, int size)
{
	int offset, byte_index, char_index;

	for (offset = 0; offset < size; offset += 10)
	{
		/* print offset */
		printf("%08x: ", offset);

		/* print bytes in hex */
		for (byte_index = 0; byte_index < 10; byte_index++)
		{
			(offset + byte_index < size) ? printf("%02x", b[offset + byte_index])
				: printf("  ");
			(byte_index % 2) ? printf(" ") : 0;
		}

		/* print bytes in ascii */
		for (char_index = 0; char_index < 10; char_index++)
			(offset + char_index < size) ? printf("%c", (b[offset + char_index] >= 32 &&
				b[offset + char_index] <= 126) ? b[offset + char_index] : '.') : 0;

		printf("\n");
	}

	(size <= 0) ? printf("\n") : 0;
}
