#include "main.h"

/**
 * handler - handling ctrl-c signal
 * @sig: number of the signal
 */
void handler(int sig __attribute__((unused)))
{
	write(1, "\nshell$ ", 9);
	signal(SIGINT, handler);
}

/**
 * errors - prints error according to case
 * @error: error statement
 * Return: void
 */
void errors(int error)
{
	switch (error)
	{
	case 1: 
		write(STDERR_FILENO, ERR_FORK, _strlen(ERR_FORK));
		perror("Error");
		break;

	case 2: 
		perror("Error");
		break;

	case 3: 
		write(STDERR_FILENO, ERR_MALLOC, _strlen(ERR_MALLOC));
		break;
	case 4: 
		write(STDERR_FILENO, ERR_PATH, _strlen(ERR_PATH));
		break;

	default:
		return;
	}
}
