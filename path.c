#include "shell.h"

/**
 */

char **getpatharray(void)
{
	char *path;
	char **patharray;
	unsigned long int num_of_tokens;

	path = getpath();

    num_of_tokens = get_num_of_tokens(path, ':');

    patharray = str_to_array(path, num_of_tokens, ":\n");

	free(path);

	return (patharray);
}

char *getpath(void)
{
    int i;
    char *path;
	/*char *envcpy;*/
	char envcpy[2048];

    for (i = 0; environ[i]; i++)
    {
        /*envcpy = strdup(environ[i]);*/
		strcpy(envcpy, environ[i]);

        if (strcmp((strtok(envcpy, "=")), "PATH") == 0)
		{
            path = strdup(strtok(NULL, "\n"));
			/*free(envcpy);*/
			return (path);
		}
		/*free(envcpy);*/
    }

    return (NULL);
}

