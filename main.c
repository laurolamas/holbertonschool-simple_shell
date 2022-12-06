#include "shell.h"

/**
 * main - Shell Main
 * Segmentation Fault cuando num of tokens es impar
 * Return: 0 on success
 * Fails when input NULL
 * Add print eror when it fails to run command
 */

int main(void)
{
	unsigned long int i;
	char *inputstr;
	char **array;
	unsigned long int num_of_tokens;
	pid_t child_id;
	int status;

	while (1)
	{
		inputstr = get_input_str();

		if (inputstr)
		{
			num_of_tokens = get_num_of_tokens(inputstr, ' ');

			array = str_to_array(inputstr, num_of_tokens, " \n");

			if ((strcmp(inputstr, "exit\n") == 0) || (strcmp(array[0], "exit") == 0))
			{
				free_grid(array, num_of_tokens);
				free(inputstr);
				return (0);
			}

			array[0] = check_cmd(array[0]);

			if (array[0])
			{
				child_id = fork();
				wait(&status);
				if (child_id == 0)
				{
					for (i = 0; i < num_of_tokens; i++)
						printf("array[%ld] - %s\n", i, array[i]);
					for (i = 0; environ[i]; i++)
						printf("%s\n", environ[i]);
					execve(array[0], array, environ);
				}
			}
			else
				printf("Error: Command not found\n");

		}
		free_grid(array, num_of_tokens);
		free(inputstr);
	}
	return (0);
}

