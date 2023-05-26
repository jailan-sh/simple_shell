#include "main.h"

/**
 * start_shell - the UNIX command line interpreter.
 * @av : pass arguments
 * @env : path
 *
 * Return: void
 */

void start_shell(char **av, char **env)
{
	char *lineptr = NULL, *delim = " \t\n\r", *lineptr_cp
	int i = 0;
	char *argument[MAX_ARGU];
	char *command_path;
	char *path;
	ssize_t num_char;
	size_t n;

	signal(SIGINT, handler);

	while (1)
	{
		write(1, "shell$ ", 7);
		lineptr  = getline(&lineptr, &n, stdin);
		if (num_char == -1)
		{
			exit(EXIT_FAILURE);
		}
		if (*lineptr != '\n')
		{
			lineptr_cp = malloc(sizeof(char) * num_char)
			if
			}
			path = _getenv("PATH");
			if (path)
			{
			command_path = which_like(argument[0]);
			if (command_path != NULL)
			execute_external_command(argument, env, av);
			}
		}
	}
	free(command_path);
	free(lineptr);
}
