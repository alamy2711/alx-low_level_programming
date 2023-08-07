#include <stdlib.h>
#include <stdio.h>

/* Prototype */
void free_memory(char **arr, int n_str);
int calc_letters(char *str, int *index);

/**
 * strtow - splits a string into words
 * @str: string to split
 * Return: NULL if str == NULL or str == "" or malloc failed
 * otherwise returns a pointer to an array of strings
 */
char **strtow(char *str)
{
	char **arr;
	int i, j, n = 0, m = 0, words = 0, letters;
	int *ptr_n = &n;

	if (str == NULL || *str == '\0')
		return (NULL);

	/* Calculate number of words */
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			words++;
	}
	arr = (char **)malloc((words + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);

	for (i = 0; i < words; i++)
	{
		/* Calculate number of letters in each word */
		letters = calc_letters(str, ptr_n);

		/* Allocate memory for each string in the array */
		arr[i] = malloc((letters + 1) * sizeof(char));
		if (arr[i] == NULL)
		{
			free_memory(arr, i);
			return (NULL);
		}

		/* Point each string to its word */
		j = 0;
		while (str[m] != '\0')
		{
			if (str[m] != ' ')
			{
				arr[i][j] = str[m];
				j++;
			}
			m++;
			if (str[m - 1] != ' ' && (str[m] == ' ' || str[m] == '\0'))
				break;
		}
		arr[i][j] = '\0';
	}
	arr[i] = NULL;

	return (arr);
}

/**
 * free_memory - frees allocated memory of an array of strings
 * @arr: the array of strings
 * @n_str: string index when malloc failed to allocate memory
 * of the array of strings
 * Return: void
 */
void free_memory(char **arr, int n_str)
{
	int i;

	for (i = 0; i < n_str; i++)
		free(arr[i]);
	free(arr);
}

/**
 * calc_letters - calculates number of letter in each word in a string
 * @str: the string containing words
 * @index: index of each word
 * Return: number of letters in each word
 */
int calc_letters(char *str, int *index)
{
	int letters = 0;

	while (str[*index] != '\0')
	{
		if (str[*index] != ' ')
			letters++;
		(*index)++;
		if (str[*index - 1] != ' ' && (str[*index] == ' ' || str[*index] == '\0'))
			break;
	}
	return (letters);
}
