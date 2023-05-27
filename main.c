#include "main.h"

/**
 * main - main function os the shell
 *
 * Return: 0 always success
 */
int main(void)
{
	if (isatty(STDIN_FILENO) == 0)
		noninteractive();
	else
		interactive();

	return (0);
}
