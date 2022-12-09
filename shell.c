#include "shell.h"

/*FIX MALLOC NUMBER*/ 
char *remove_spaces_from_beginning(char *str)
{
	int i = 0, k = 0;
	char *cpy;

    while (str[i] == ' ')
	{
        i++;
	}

	if (i == 0)
		return (str);

/*	printf ("strsize = %ld i = %d\n", sizeof(str), i);*/

	/*cpy = malloc (sizeof(str) - i);*/
	cpy = malloc (1024);

	while (str[i] != '\0')
	{
		cpy[k] = str[i];
		i++;
		k++;
	}
	cpy[k] = '\0';

	free(str);
	return (cpy);
}

/**
 * get_num_of_tokens - Gets number of words in string
 * @string: string
 * Return: ul
 */

unsigned long int get_num_of_tokens(const char *string, char delim)
{


	int count = 1;
	char *ptr = NULL;
	char *ptrcpy = NULL;

	ptr = strdup(string);
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
		array[i] = strdup(token);
		token = strtok(NULL, delim);
		i++;
	}
	array[i] = NULL;

	return (array);
}


/**
 * get_input_str - Gets string prom stdin input
 *
 * Return: string
 */

char *get_input_str(void)
{
	char *str = NULL;
	size_t len = 1;

	printf("$ ");

	getline(&str, &len, stdin);

	str = remove_spaces_from_beginning(str);

	if (strcmp(str, "\n") == 0)
	{
		free(str);
		return (NULL);
	}

	str = strtok(str, "\n");

	return (str);
}

/**
 * NUm of tokens arrreglar
 */

char *check_cmd(char **args, char **patharray)
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
		strcpy(test, patharray[i]);
		strcat(test, "/");
		strcat(test, args[0]);

		if (stat(test, &st) == 0)
		{
			free(args[0]);
			free(path);
			args[0] = strdup(test);
			return (args[0]);
		}
	}
	free(path);
	free(args[0]);
	return (NULL);

}
