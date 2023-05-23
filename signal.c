#include "main.h"

/**
 * handler - handling ctrl-c signal
 *
 * @sig: number of the signal
 */
void handler(int sig __attribute__((unused)))
{
	write(1, "\nshell$ ", 9);
	signal(SIGINT, handler);
}
