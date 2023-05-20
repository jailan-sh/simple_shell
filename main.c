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
	if (ac == 1)
		start_shell(av, env);
	return (0);
}
