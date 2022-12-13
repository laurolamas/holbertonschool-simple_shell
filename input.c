#include "shell.h"

/**
 * remove_spaces_from_beginning - Remove trailing whitespaces from string
 * @str: string
 * Return: New string
 */
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

	/*printf ("strsize = %ld i = %d\n", sizeof(str), i);*/

	/*FIX MALLOC NUMBER*/
	/*cpy = malloc (sizeof(str) - i);*/
	cpy = malloc(1024);

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
 * get_input_str - Gets string prom stdin input
 *@mode: int = 1
 *
 * Return: string
 */

char *get_input_str(int mode)
{
	char *str = NULL;
	size_t len = 1;
	char characters;

	if (mode)
		printf("$ ");

	characters = getline(&str, &len, stdin);
	(characters == -1) ? free(str), exit(0) : (void) 0;/*chec EOF (CRL + D*/

	str = remove_spaces_from_beginning(str);

	if (_strcmp(str, "\n") == 0)
	{
		free(str);
		return (NULL);
	}

	str = strtok(str, "\n");

	return (str);
}
