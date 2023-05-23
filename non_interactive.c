#include "main.h"
#define MAX_ARGU 1024

/**
 * non_interactive - function that reads commands from a file or from another
 *                    program's output.
 * @av: list of arguments
 * @env: environment variables
 *
 * Return: void
 */
void non_interactive(char **av, char **env)
{
	char buffer[MAX_ARGU];
	char *delim = " \t\n\r";
	int i = 0;
	char *argument[MAX_ARGU];

	while (fgets(buffer, sizeof(buffer), stdin) != NULL)
	{
		i = 0;
		argument[i] = _strtok(buffer, delim);
		if (argument[i] == NULL)
		{
			continue;
		}
		while (argument[i] && i < MAX_ARGU - 1)
		{
			if (i > 0 && argument[i] != NULL &&
					_strcmp(argument[i], "#") == 0)
			{
				argument[i] = NULL;
				break;
			}
			argument[++i] = _strtok(NULL, delim);
		}
		execute_builtin_command(argument, env, av);
	}
}
