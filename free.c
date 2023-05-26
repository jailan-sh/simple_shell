#include "main.h"

/**
 * free_all - frees all malloc'd space at end of main loop
 * @tokens: pointer to tokens array
 * @path: pointer to path variable
 * @line: pointer to user input buffer
 * @full_path: pointer to full path
 * @flag: flag marking if full_path was malloc'd
 * Return: void
 */
void free_all(char **tokens, char *path, char *line, char *full_path, int flag)
{
	free(path);
	free(line);
	free(tokens);
	if (flag == 1)
		free(full_path);
}

