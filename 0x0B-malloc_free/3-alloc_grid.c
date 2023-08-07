#include <stdlib.h>
#include <stdio.h>

/* Prototype */
void free_memory(int **grid, int n_row);

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
		{
			free_memory(grid, i);
			return (NULL);
		}

		for (j = 0; j < width; j++)
			grid[i][j] = 0;
	}

	return (grid);
}

/**
 * free_memory - frees allocated memory of a 2D array
 * @grid: the 2D array
 * @n_row: row number when malloc failed to allocate memory of the 2D array
 * Return: void
*/
void free_memory(int **grid, int n_row)
{
	int i;

	for (i = 0; i < n_row; i++)
		free(grid[i]);
	free(grid);
}
