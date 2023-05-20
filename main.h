#ifndef MAIN_h_
#define MAIN_h_

#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

extern char **environ;

void execute_command(char** argument, char** env, char* av[]);
void start_shell(char **av, char **env);
char *which_like(char *command);
void execute(char**argv);
char *_getenv(const char *var);
void print_env(void);

/**string functions */

char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strncat(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
unsigned int _strspn(char *s, char *accept);
char *_strdup(char *str);
void _puts(char *s);

#endif
