#include "main.h"
/**
 * execute_command - to execute and fork command
 * @argument : command
 * @env : environment
 * @av : argument vector
 *
 * Return: void
 */

void execute_command(char **argument, char **env, char *av[])
{
	pid_t child;
	int status;

	if (strcmp("env", argument[0]) == 0)
	{
		print_env();
	}
	child = fork();
	if (child == -1)
	{
		free(argument), exit(EXIT_FAILURE);
	}
	if (child == 0)
	{
		if (execve(argument[0], argument, env) == -1)
			printf("%s: No such file or directory\n", av[0]);
	}
	else
	{
		wait(&status);
	}
}
