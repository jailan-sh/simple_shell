#include "main.h"

/**
 * tokenizer - tokenizes string
 * @str: user input
 * Return: pointer to array of tokens
 */

char **tokenizer(char *str)
{
		char **tokens;
	unsigned int i = 0;

	tokens = malloc(sizeof(char) * BUFFER);
	if (tokens == NULL)
	{
		errors(3);
		exit(EXIT_FAILURE);
	}

	tokens[i] = strtok(str, "\n\t\r ");
	while (tokens[i])
	{
		if (i > 0 && tokens[i] != NULL && strcmp(tokens[i], "#") == 0)
		{
			tokens[i] = '\0';
			break;
		}
				tokens[++i] = strtok(NULL, "\n\t\r ");
	}
	return (tokens);
}
