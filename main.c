#include "shell.h"

int fork_and_exec(char **args)
{
	pid_t id;
	int status;

	id = fork();

	wait(&status);

	if (id == 0)
	{
		execve(args[0], args, environ);
		printf("Error: Exec failed\n");
		return (0);
	}

	return (status);
}

/**
 * main - Shell Main
 * Segmentation Fault cuando num of tokens es impar
 * Return: 0 on success
 * Fails when input NULL
 * Add print eror when it fails to run command
 */

int main(void)
{
	char *inputstr;
	char **array;
	uli num_of_tokens;
	int status = 0;
	char **patharray = getpatharray();
	char *path = getpath();
	uli path_tokens = get_num_of_tokens(path, ':');
	int mode = 1;

	free(path);

	while (mode)
	{
		mode = isatty(STDIN_FILENO);

		inputstr = get_input_str(mode);

		if (inputstr)
		{
			num_of_tokens = get_num_of_tokens(inputstr, ' ');

			array = str_to_array(inputstr, num_of_tokens, " \n");
			if ((_strcmp(inputstr, "exit\n") == 0) || (_strcmp(array[0], "exit") == 0))

			array = str_to_array(inputstr, num_of_tokens, " \n\t");

			if ((_strcmp(inputstr, "exit\n") == 0) || (_strcmp(array[0], "exit") == 0))
			{
				free_all(array, num_of_tokens, patharray, path_tokens, inputstr);
				return (WEXITSTATUS(status));
			}

			array[0] = check_cmd(array, patharray);

			if (array[0])
				status = fork_and_exec(array);

			free_grid(array, num_of_tokens);
			free(inputstr);
		}
	}
	
	free_grid(patharray, path_tokens);
	return (0);
}
