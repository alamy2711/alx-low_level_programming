#include <stdlib.h>

/**
 * free_grid - frees a 2 dimensional grid
 * @grid: the 2 dimensional grid
 * @height: height of the 2D grid
 * Return: void
 */
void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
		free(grid[i]);
	free(grid);
}
