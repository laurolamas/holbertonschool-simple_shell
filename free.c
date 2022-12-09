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

/**
 * free_all - free all
 *
 * @args: args
 * @nargs: nargs
 * @path: path
 * @npath: npath
 * @input: input
 *
 */

void free_all(char **args, uli nargs, char **path, uli npath, char *input)
{
	free_grid(args, nargs);
	free_grid(path, npath);
	free(input);
}
