#include "variadic_functions.h"

/**
 * print_all - Prints anything
 * @format: List of types of arguments passed to the function
 */
void print_all(const char *const format, ...)
{
	int i = 0, was_printed;
	char character;
	int integer;
	float decimal;
	char  *string;
	va_list args;

	va_start(args, format);
	while (format != NULL && format[i] != '\0')
	{
		was_printed = 1;
		switch (format[i])
		{
			case 'c':
				character = va_arg(args, int);
				printf("%c", character);
				break;
			case 'i':
				integer = va_arg(args, int);
				printf("%d", integer);
				break;
			case 'f':
				decimal = va_arg(args, double);
				printf("%f", decimal);
				break;
			case 's':
				string = va_arg(args, char *);
				if (string == NULL)
					string = "(nil)";
				printf("%s", string);
				break;
			default:
				was_printed = 0;
		}
		if (format[i + 1] != '\0' && was_printed == 1)
			printf(", ");
		i++;
	}
	va_end(args);
	printf("\n");
}
