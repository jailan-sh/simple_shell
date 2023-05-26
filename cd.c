#include "main.h"
#include <limits.h>

/**
 * my_cd - function to change dir
 * @argument : command
 *
 * Return: 0 success otherwise -1
 */

int my_cd(char **argument)
{
	char cwd[PATH_MAX];

	if (argument == NULL ||
			argument[0] == NULL || strcmp(argument[0], "cd") != 0)
	{
		return (-1);
	}
	if (argument[1] == NULL || strcmp(argument[1], "~") == 0)
	{
		chdir(_getenv("HOME"));
	}
	else if (strcmp(argument[1], "-") == 0)
	{
		if (_getenv("OLDPWD") != NULL)
		{
			chdir(_getenv("OLDPWD"));
		}
		else
		{
			/**write(2, "./hsh: cd: OLDPWD not set\n", 27);*/
			fprintf(stderr, "./hsh: cd: OLDPWD not set\n");
			return (-1);
		}
	}
	else
	{
		if (chdir(argument[1]) == -1)
		{
			perror("cd");
			return (-1);
		}
	}
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		return (-1);
	}
	setenv("OLDPWD", _getenv("PWD"), 1);
	setenv("PWD", cwd, 1);
	return (0);
}
