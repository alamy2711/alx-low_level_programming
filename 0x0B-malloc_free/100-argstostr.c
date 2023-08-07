#include <stdlib.h>
#include <stdio.h>

/**
 * argstostr - concatenates all the arguments
 * @ac: arguments count
 * @av: arguments vector
 * Return: NULL if ac == 0 or av == NULL or malloc failed
 * otherwise returns a pointer to a new string
 */
char *argstostr(int ac, char **av)
{
	char *str;
	int i, j, len = 0, tracker = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	/* Calculate total length */
	for (i = 1; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
			len++;
		len++;
	}

	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);

	for (i = 1; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
			str[tracker++] = av[i][j];

		str[tracker++] = '\n';
	}
	str[tracker] = '\0';

	return (str);
}
