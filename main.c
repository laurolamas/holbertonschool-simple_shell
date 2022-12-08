#include "shell.h"

void free_all(char **args, unsigned long int nargs, char **path, unsigned long int npath, char *inputstr)
{
	free_grid(args, nargs);
	free_grid(path, npath);
	free(inputstr);
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
	unsigned long int num_of_tokens;
	pid_t child_id;
	int status;
	char **patharray = getpatharray();

	while (1)
	{
		inputstr = get_input_str();
		if (inputstr)
		{
			num_of_tokens = get_num_of_tokens(inputstr, ' ');
			array = str_to_array(inputstr, num_of_tokens, " \n");
			if ((strcmp(inputstr, "exit\n") == 0) || (strcmp(array[0], "exit") == 0))
			{
				free_all(array, num_of_tokens, patharray, 10, inputstr);
				/**free_grid(array, num_of_tokens);
				free_grid(patharray, 10);
				free(inputstr);*/
				return (0);
			}

			array[0] = check_cmd(array, patharray);

			if (array[0])
			{
				child_id = fork();
				wait(&status);
				if (child_id == 0)
					execve(array[0], array, environ);
			}
			else
				printf("Error: Command not found\n");

		free_grid(array, num_of_tokens);
		free(inputstr);
		}
	}
	free_grid(patharray, 10);
	return (0);
}

