#include "shell.h"

/**
 * get_num_of_tokens - Gets number of words in string
 * @string: string
 * Return: ul
 */

unsigned long int get_num_of_tokens(const char *string, char delim)
{


	int count = 1;
	char *ptr = NULL;

	ptr = strdup(string);

	while ((ptr = strchr(ptr, delim)) != NULL)
	{
		count++;
		ptr++;
	}

	free(ptr);

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

	if (strcmp(str, "\n") == 0)
	{
		free(str);
		return (NULL);
	}

	return (str);
}

/**
 * NUm of tokens arrreglar
 */

char *check_cmd(char *s)
{
	unsigned long int i;
	char *test = NULL;
	char **patharray;
	unsigned long int num_of_tokens = 10;
	struct stat st;

	if (stat(s, &st) == 0)
		return (s);

	patharray = getpatharray();

	for (i = 0; i < num_of_tokens; i++)
	{
		test = malloc(strlen(patharray[i]) + strlen(s) + 2);
		test[0] = 0;
		strcat(test,patharray[i]);
		strcat(test, "/");
		strcat(test, s);

		if (stat(test, &st) == 0)
		{
			free_grid(patharray, num_of_tokens);
			free(s);
			return (test);
		}
	}
	
	free_grid(patharray, num_of_tokens);
	return (NULL);

}
