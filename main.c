#include "main.h"
#include <signal.h>

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

	if (isatty(STDIN_FILENO))
	{
		start_shell(av, env);	
	}
	else
	{
		non_interactive(av, env);
	}	
	return (0);
}
