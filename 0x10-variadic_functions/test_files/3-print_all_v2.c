#include "variadic_functions.h"

/**
 * struct specifier - Struct specifier
 * @specifier: The specifier
 * @func: The Specifier's function
*/
typedef struct specifier
{
	char specifier;
	void (*func)(va_list);
} specifier_t;

/* Prototypes */
void print_c(va_list args);
void print_i(va_list args);
void print_f(va_list args);
void print_s(va_list args);

/**
 * print_all - Prints anything
 * @format: List of types of arguments passed to the function
 */
void print_all(const char *const format, ...)
{
	int i = 0, j;
	char *separator = "";
	specifier_t specifiers[4] = {
		{'c', print_c},
		{'i', print_i},
		{'f', print_f},
		{'s', print_s}};

	va_list args;

	va_start(args, format);

	while (format != NULL && format[i] != '\0')
	{
		j = 0;
		while (j < 4)
		{
			if (format[i] == specifiers[j].specifier)
			{
				printf("%s", separator);
				specifiers[j].func(args);
				separator = ", ";
			}
			j++;
		}
		i++;
	}
	va_end(args);
	printf("\n");
}

/**
 * print_c - Prints a character
 * @args: Character to print
 */
void print_c(va_list args)
{
	printf("%c", va_arg(args, int));
}

/**
 * print_i - Prints an integer
 * @args: Integer to print
 */
void print_i(va_list args)
{
	printf("%d", va_arg(args, int));
}

/**
 * print_f - Prints a float number
 * @args: Float number to print
 */
void print_f(va_list args)
{
	printf("%f", va_arg(args, double));
}

/**
 * print_s - Prints a string
 * @args: String to print
 */
void print_s(va_list args)
{
	char *s = va_arg(args, char *);

	if (s == NULL)
	{
		printf("(nil)");
		return;
	}
	printf("%s", s);
}
