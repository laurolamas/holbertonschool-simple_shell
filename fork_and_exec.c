#include "shell.h"

/**
*fork_and_exec - fork and excve
*@args: arguments
*
*Return: status
*/

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
