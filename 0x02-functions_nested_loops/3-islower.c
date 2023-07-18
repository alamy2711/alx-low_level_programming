#include <ctype.h>

/**
 * _islower - checks for lowercase character.
 *
 * Returns: 1 if c is lowercase
 * Returns 0 otherwise
 */
int _islower(int c)
{
	if (islower(c))
		return (0);
	else
		return (1);
}
