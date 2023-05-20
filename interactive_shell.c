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
	char *lineptr = NULL, *delim = " \t\n\r";
	size_t n = 0;
	int i = 0;
	ssize_t nread;
	char *argument[MAX_ARGU];

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("simple_shell$ ");
		nread = getline(&lineptr, &n, stdin);
		if (nread == -1)
		{
			write(1, "\n", 2);
			free(lineptr), exit(EXIT_FAILURE);
		}

		if (*lineptr != '\n')
		{
			i = 0;
			argument[i] = _strtok(lineptr, delim);
			if (_strcmp("exit", argument[0]) == 0)
				break;
			while (argument[i])
				argument[++i] = _strtok(NULL, delim);
			if (which_like(argument[0]) != NULL)
			{
				execute(argument);
			}
			else
			{
				execute_command(argument, env, av);
			}
		}
	}
	free(lineptr);
}
