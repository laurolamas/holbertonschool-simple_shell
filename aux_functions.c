#include "shell.h"

/**
*_strcmp - compares the two strings str1 and str2
*@str1: string to compare
*@str2: string to compare
*
*Return: 0, if the str1 and str2 are equal
*a negative value if str1 is less than str2;
*a positive value if str1 is greater than str2.
*/

int _strcmp(const char *str1, const char *str2)
{
	int i;

	for (i = 0; str1[i] == str2[i] && str1[i] != '\0'; i++)
	{
	}
	if (str1[i] != str2[i])
	{
	return ((str1[i] - str2[i]));
	}
	else
	{
		return (0);
	}

}
/**
*_strcpy - copy the string to a buffer
 * @dest: pointer
 * @src: pointer
 * Return: a pointer to the destination string dest
*/
char *_strcpy(char *dest, const char *src)
{
	int r = 0;

	for (; src[r] != '\0'; r++)
	{
		dest[r] = src[r];
	}

	dest[r] = '\0';

	return (dest);
}

/**
 * _strdup - copy of the string given as a parameter
 * @str: string of char
 *
 *Return: a pointer to a new string
 *  duplicate of str, NULL if str = NULL
 */

char *_strdup(const char *str)
{
	int i, j;
	char *array;

	if (str == NULL)
		return (NULL);

	for (i = 0 ; str[i] != '\0' ; i++)
	{
	}

	array = malloc(sizeof(char) * i + 1);

	if (array == NULL)
		return (NULL);

	for (j = 0 ; j <= i ; j++)
		array[j] = str[j];

	return (array);
}
/**
 * _strcat - appends the src string to the dest string
 * @dest: stores a string
 * @src: stores a string
 * Return: pointer to string dest
 **/

char *_strcat(char *dest, char *src)
{
	char *dest_aux;
	const char *src_aux;

	dest_aux = dest;
	src_aux =  src;

	while (*dest_aux != '\0')
		dest_aux++;

	while (*src_aux != '\0')
		*dest_aux++ = *src_aux++;
	*dest_aux = '\0';
	return (dest);
}
