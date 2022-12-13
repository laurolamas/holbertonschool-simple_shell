#include "shell.h"

/**
 * main - Shell Main
 *
 * Return: Exit status of last command used, or 0 if no command passed.
 */

int main(__attribute__((unused)) int argc, char **argv)
{
	char *inputstr, **array, *path = getpath();
	char **patharray = getpatharray();
	int mode = 1, status = 0;
	uli num_of_tokens;
	uli path_tokens = get_num_of_tokens(path, ':');

	free(path);
	while (mode)
	{
		mode = isatty(STDIN_FILENO);
		inputstr = get_input_str(mode);
		if (inputstr)
		{
			num_of_tokens = get_num_of_tokens(inputstr, ' ');
			array = str_to_array(inputstr, num_of_tokens, " \n\t");
			if ((_strcmp(inputstr, "exit\n") == 0) || (_strcmp(array[0], "exit") == 0))
			{
				free_all(array, num_of_tokens, patharray, path_tokens, inputstr);
				return (WEXITSTATUS(status));
			}
			array[0] = check_cmd(array, patharray, argv[0]);
			if (array[0])
				status = fork_and_exec(array);
			free_grid(array, num_of_tokens);
			free(inputstr);
		}
	}
	free_grid(patharray, path_tokens);
	return (0);
}
