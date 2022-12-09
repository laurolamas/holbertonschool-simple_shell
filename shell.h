#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define PATH_MAX_TOKENS 10


typedef unsigned long int uli;


extern char **environ;

unsigned long int get_num_of_tokens(const char *string, char delim);
char **str_to_array(char *buffer, unsigned long int n, char *delim);
char *get_input_str(void);
char *check_cmd(char **args, char **patharray);
void free_grid(char **grid, int height);
char **getpatharray(void);
char *getpath(void);

#endif
