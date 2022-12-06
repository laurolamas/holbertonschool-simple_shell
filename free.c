#include "shell.h"

/**
 * free_grid - free grid
 *
 * @grid: grid
 * @height: height
 *
 * Return: voidd
 */

void free_grid(char **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
		free(grid[i]);

	free(grid);
}
