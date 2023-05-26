#include "main.h"

/**
 * _getline - function like getline
 *
 * Return: string success otherwise NULL
 */
char *_getline(void)
{
	static char buffer[1024];
	static int pos;
	int c;

	while ((c = getchar()) != EOF && c != '\n')
	{
		buffer[pos++] = c;
		if (pos >= 1024)
		{
			write(1, "Error: input too long\n", 23);
			return (NULL);
		}
	}
	if (pos == 0 && c == EOF)
	{
		return (NULL);
	}
	buffer[pos] = '\0';
	pos = 0;
	return (buffer);
}
