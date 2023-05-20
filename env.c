#include "main.h"

/**
 * print_env - function to print environment
 *
 * Return: void
 */

void print_env(void)
{
	unsigned int i, length;

	i = 0;
	while (environ[i] != NULL)
	{
		length = strlen(environ[i]);
		write(STDOUT_FILENO, environ[i], length);
		write(STDOUT_FILENO, "\n", 1);
		i++;
		fflush(stdout);
	}
}
