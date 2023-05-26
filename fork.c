#include "main.h"

/**
 * fork - function in child process
 * @full_path: path of executable command
 * @tokens: tokenized user input
 *
 * Return: 0 is always success
 */

int child(char *full_path, char **tokens)
{
	pid_t child_pid;
	int status;
	int execve_status;
	char **envp = environ;

	child_pid = fork();
	if (child_pid == -1)
	{
		errors(1);
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		execve_status = execve(full_path, tokens, envp);
		if (execve_status == -1)
			return (-1);
	}
	else
		wait(&status);

	return (0);
}
