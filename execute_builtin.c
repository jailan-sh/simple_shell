#include "main.h"

/**
 * execute_builtin_command - executes builtin commands
 * @argument: command arguments
 *
 * Return: 0 success otherwise 1 failed
 */

int execute_builtin_command(char **argument)
{
	if (argument == NULL || argument[0] == NULL)
	{
		return (0);
	}
	else if (argument[1] != NULL &&
			strcmp("echo", argument[0]) == 0 && strcmp("$$", argument[1]) == 0)
	{
		_echo();
		return (0);
	}
	else if (strcmp("env", argument[0]) == 0)
	{
		print_env();
		return (0);
	}
	else if (strcmp(argument[0], "exit") == 0)
	{
		return (-1);
		exit(0);
	}
	else if (strcmp(argument[0], "#") == 0)
	{
		return (0);
	}
	else if (strcmp("cd", argument[0]) == 0)
	{
		my_cd(argument);
		return (0);
	}
	else
	{
		return (1);
	}
	return (0);
}
