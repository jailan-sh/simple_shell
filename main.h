#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER 1024
#define PROMPT "shell$ "

extern char **environ;

/* error strings */

#define ERR_MALLOC "Unable to malloc space\n"
#define ERR_FORK "Unable to fork and create child process\n"
#define ERR_PATH "No such file or directory\n"

/**
 * struct list_s - linked list of variables
 * @value: value
 * @next: pointer to next node
 *
 * Description: list struct for variables.
**/

typedef struct list_s
{
	char *value;
	struct list_s *next;
} list_s;

/**
 * struct built_s - linked list of builtins
 * @name: name of builtin
 * @p: pointer to function
 *
 * Description: struct for builtin functions.
**/

typedef struct built_s
{
	char *name;
	int (*p)(void);
} built_s;

/**shell functions*/

void noninteractive(void);
void interactive(void);
void shell(int fd, struct stat buf);
char *_getline(FILE *fp);
char **tokenizer(char *str);
char *_which(char *command, char *fullpath, char *path);
int child(char *fullpath, char **tokens);
void errors(int error);

/* string functions */
void _puts(char *str);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_strdup(char *str);
int _strcmp(char *name, char *variable, unsigned int length);
int _strncmp(char *name, char *variable, unsigned int length);
char *_strcpy(char *dest, char *src);
unsigned int _strspn(char *s, char *accept);


/**signal handler */
void handler(int sig __attribute__((unused)));
int shell_num_builtins(built_s builtin[]);


/* functions add to get the path */
char *_getenv(const char *name);
char **copy_env(char **environ_copy, unsigned int environ_length);
list_s *pathlist(char *variable, list_s *head);

/**free the memory*/
void free_all(char **tokens, char *path, char *line, char *fullpath, int flag);
void free_array(char **array, unsigned int len);

/** builtin functions*/
int execute_builtin_command(char **argument);
void print_env(void);
void _echo(void);
int my_cd(char **argument);

#endif
