#include "shell.h"

/**
 * get_num_of_tokens - Gets number of words in string
 * @string: string
 * Return: ul
 */

unsigned long int get_num_of_tokens(const char *string)
{


	int count = 1;
	char *ptr = NULL;

	ptr = strdup(string);

	while ((ptr = strchr(ptr, ' ')) != NULL)
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

char **str_to_array(char *buffer, unsigned long int n)
{

	char *s = " \n";
	char *token;
	char **array;
	int i = 0;

	/*Allocate memory for array*/
	array = malloc(sizeof(char *) * n);

	/* get the first token */
	token = strtok(buffer, s);

	/* walk through other tokens */
	while (token)
	{
		array[i] = strdup(token);
		token = strtok(NULL, s);
		i++;
	}

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
		return (NULL);

	return (str);
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


	while (1)
	{

		/* Gets input string*/
		inputstr = get_input_str();
		/*printf("%s\n", inputstr);*/

		if (inputstr)
		{

			/*Gets num of tokens*/
			num_of_tokens = get_num_of_tokens(inputstr);

			/*Separate input string into array of args*/
			array = str_to_array(inputstr, num_of_tokens);

			/*Checks if input string or first arg of array equals "exit"*/
			if ((strcmp(inputstr, "exit\n") == 0) || (strcmp(array[0], "exit") == 0))
				return (0);

			/*forks and if child execute command, in case of no command returns 0*/
			child_id = fork();
			wait(&status);
			if (child_id == 0)
			{
				execve(array[0], array, NULL);
				printf("Error: Command not found\n");
				return (0);
			}
		}
	}
	return (0);
}
