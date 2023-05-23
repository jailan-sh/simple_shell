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
	int i = 0;
	char *argument[MAX_ARGU];

	signal(SIGINT, handler);

	while (1)
	{
		write(1, "shell$ ", 7);
		lineptr  = _getline();
		if (lineptr == NULL)
		{
			write(1, "exit\n", 6);
			free(lineptr), exit(EXIT_FAILURE);
		}
		if (*lineptr != '\n')
		{
			i = 0;
			argument[i] = _strtok(lineptr, delim);

			while (argument[i])
			{
				if (i > 0 && argument[i] != NULL && _strcmp(argument[i], "#") == 0)
				{
					argument[i] = '\0';
				}
				argument[++i] = _strtok(NULL, delim);
			}
			execute_builtin_command(argument, env, av);
		}
	}
	free(lineptr);
}
