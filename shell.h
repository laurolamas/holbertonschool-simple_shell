#ifndef SHELL_H
#define SHELL_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>


typedef unsigned long int uli;


extern char **environ;

unsigned long int get_num_of_tokens(const char *string, char delim);
char **str_to_array(char *buffer, unsigned long int n, char *delim);
char *get_input_str(int mode);
char *check_cmd(char **args, char **patharray);
void free_grid(char **grid, int height);
char **getpatharray(void);
char *getpath(void);
void free_all(char **args, uli nargs, char **path, uli npath, char *input);

/*aux function*/
int _strcmp(const char *str1, const char *str2);
char *_strcpy(char *dest, const char *src);
char *_strdup(const char *str);
char *_strcat(char *dest, char *src);

#endif
