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

/*  printf ("strsize = %ld i = %d\n", sizeof(str), i);*/

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

