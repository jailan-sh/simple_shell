#include "main.h"

/**
 * which_like - get path of the command
 *
 * Return: path if exist or NULL if not
 * @command : command entered by user
 */
char *which_like(char *command)
{
	char *path, *path_cp, *path_token, *file_path;
	int command_len, directory_len;
	struct stat buff;
	char *error_msg;

	path = _getenv("PATH");
	if (path)
	{
		path_cp = _strdup(path);
		command_len = _strlen(command);
		path_token = _strtok(path_cp, ":");
		while (path_token != NULL)
		{
			directory_len = _strlen(path_token);
			file_path = malloc(command_len + directory_len + 2);
			_strcpy(file_path, path_token);
			_strcat(file_path, "/");
			_strcat(file_path, command);
			_strcat(file_path, "\0");
			if (stat(file_path, &buff) == 0)
			{
				free(path_cp);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
	free(path_cp);
	if (stat(command, &buff) == 0)
	{
		return (command);
	}
	else
	{
		error_msg = "command not found\n";
		write(STDERR_FILENO, error_msg, _strlen(error_msg));
	}
	return (NULL);
	}
	return (NULL);
}

/**
 * _getenv - function to get to environment variables
 * @var : path
 *
 * Return: environ if exist, null if not
 */

char *_getenv(const char *var)
{
	int index, len;

	len = _strlen(var);
	for (index = 0; environ[index]; index++)
	{
		if (_strncmp(var, environ[index], len) == 0)
			return (environ[index]);
	}
	return (NULL);
}
