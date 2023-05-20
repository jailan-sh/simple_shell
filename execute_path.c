#include  "main.h"

/**
 * execute - to execute commands
 *
 * Return:void
 * @argv:command to be executed
 */

void execute(char **argv)
{
	int status;
	pid_t pid;
	char *command = NULL;
	char *command_path = NULL;

	if (argv)
	{
		command = argv[0];
		command_path = which_like(command);
		if (command_path == NULL)
		{
			printf("%s: command not found\n", command);
			return;
		}
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			return;
		}
		else if (pid == 0)
		{
			if (execve(command_path, argv, environ) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (waitpid(pid, &status, 0) == -1)
			{
				perror("waitpid");
				return;
			}
		}
	}
}
