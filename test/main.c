#include "main.h"

/**
 * main - main function to run shell
 * @ac : number count of arguments
 * @av : string of arguments
 * @env : environment varuables
 *
 * Return: 0 always success
 */

int main(int ac, char **av, char **env)
{
	(void)ac;

	if (isatty(STDIN_FILENO) != 0 && ac > 1)
	{
		non_interactive(av, env);
	}
	else
	{
		start_shell(av, env);
	}
	return (0);
}
