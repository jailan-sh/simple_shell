#include "main.h"

/**
 * _which - searches directories in PATH for command
 * @command: to search for
 * @full_path: path of command to execute
 * @path: PATH variable
 * Return: pointer to full_path
 */
char *_which(char *command, char *full_path, char *path)
{
	unsigned int command_len, path_len, original_path_len;
	char *path_copy, *token;

	command_len = _strlen(command);
	original_path_len = _strlen(path);
	path_copy = malloc(sizeof(char) * original_path_len + 1);
	if (path_copy == NULL)
	{
		errors(3);
		return (NULL);
	}
	_strcpy(path_copy, path);
	token = strtok(path_copy, ":");
	if (token == NULL)
		token = strtok(NULL, ":");
	while (token != NULL)
	{
		path_len = _strlen(token);
		full_path = malloc(sizeof(char) * (path_len + command_len) + 2);
		if (full_path == NULL)
		{
			errors(3);
			return (NULL);
		}
		_strcpy(full_path, token);
		full_path[path_len] = '/';
		_strcpy(full_path + path_len + 1, command);
		full_path[path_len + command_len + 1] = '\0';
		if (access(full_path, X_OK) != 0)
		{
			free(full_path);
			full_path = NULL;
			token = strtok(NULL, ":");
		}
		else
			break;
	}
	free(path_copy);
	return (full_path);
}
