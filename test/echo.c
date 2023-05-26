#include "main.h"

/**
 * _echo - to print pid
 *
 * Return: void
 */

void _echo(void)
{
	int pid;

		pid = getpid();
		printf("%i\n", pid);
}
