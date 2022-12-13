#include "shell.h"

/**
 * get_num_of_tokens - Gets number of words in string
 * @string: string
 * @delim: delimiter
 *
 * Return: ul
 */

unsigned long int get_num_of_tokens(const char *string, char delim)
{


	int count = 1;
	char *ptr = NULL;
	char *ptrcpy = NULL;

	ptr = _strdup(string);
	ptrcpy = ptr;

	while ((ptr = strchr(ptr, delim)) != NULL)
	{
		count++;
		ptr++;
	}

	free(ptrcpy);

	return (count);
}

/**
 * str_to_array -  splits a string from imput and
 * returns an array of each word of the string.
 *
 * @buffer: buffer
 * @n: Num of tokens
 * @delim: delimiter
 *
 * Return: Pointer to array of strings
 */

char **str_to_array(char *buffer, unsigned long int n, char *delim)
{

	char *token;
	char **array;
	int i = 0;

	/*Allocate memory for array*/
	array = malloc(sizeof(char *) * (n + 1));

	/* get the first token */
	token = strtok(buffer, delim);

	/* walk through other tokens */
	while (token)
	{
		array[i] = _strdup(token);
		token = strtok(NULL, delim);
		i++;
	}
	array[i] = NULL;

	return (array);
}

/**
 * check_cmd - check cmd existence
 *@args: arguments
 *@patharray: pointer to patharray pointepointer to patharray pointerr
 *Return: args or NULL
 */

char *check_cmd(char **args, char **patharray, char *argv0)
{
	unsigned long int i;
	char test[1024];
	char *path;
	unsigned long int num_of_tokens;
	struct stat st;

	if (stat(args[0], &st) == 0)
		return (args[0]);

	path = getpath();
	num_of_tokens = get_num_of_tokens(path, ':');

	for (i = 0; i < num_of_tokens; i++)
	{
		_strcpy(test, patharray[i]);
		_strcat(test, "/");
		_strcat(test, args[0]);

		if (stat(test, &st) == 0)
		{
			free(args[0]);
			free(path);
			args[0] = _strdup(test);
			return (args[0]);
		}
	}
	fprintf(stderr, "%s: 1: %s: not found\n", argv0, args[0]);
	free(path);
	free(args[0]);
	return (NULL);

}
