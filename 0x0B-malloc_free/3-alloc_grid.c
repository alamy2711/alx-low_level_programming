#include <stdlib.h>
#include <stdio.h>

/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers
 * @width: width of the 2D array
 * @height: height of the 2D array
 * Return: NULL if width or height is 0 or negative ormalloc failed
 * otherwise returns concatenated string
 */
int **alloc_grid(int width, int height)
{
	int **grid;
	int i, j;

	if (width <= 0 || height <= 0)
		return (NULL);

	grid = (int **)malloc(height * sizeof(int *));
	if (grid == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
	{
		grid[i] = malloc(width * sizeof(int));
		if (grid[i] == NULL)
			return (NULL);

		for (j = 0; j < width; j++)
			grid[i][j] = 0;
	}

	return (grid);
}
