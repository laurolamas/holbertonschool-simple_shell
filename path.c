#include "shell.h"

/**
 */

char **getpatharray(void)
{
	int i;
	char *path;
	char **patharray;
	unsigned long int num_of_tokens;
	char *envcpy;

	for(i = 0; environ[i]; i++)
	{
		envcpy = strdup(environ[i]);
        if (strcmp((strtok(envcpy, "=")), "PATH") == 0)
		{
            path = strtok(NULL, "\n");
			break;
		}
		free(envcpy);
	}

	path = strtok(path, "\n");

    num_of_tokens = get_num_of_tokens(path, ':');

    patharray = str_to_array(path, num_of_tokens, ":\n");

	return (patharray);
}

char *getpath(void)
{
    int i;
    char *path;

    for(i = 0; environ[i]; i++)
        if (strcmp((strtok(environ[i], "=")), "PATH") == 0)
            path = strtok(NULL, "\n");

    return (path);
}

