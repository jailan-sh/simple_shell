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

	path = _getenv("PATH");
	if (!path)
		return (NULL);
	path_cp = _strdup(path);
	if (!path_cp)
		return (NULL);
	command_len = _strlen(command);
	path_token = _strtok(path_cp, ":");
	while (path_token != NULL)
	{
		directory_len = _strlen(path_token);
		file_path = malloc(command_len + directory_len + 2);
		if (!file_path)
		{
			free(path_cp);
			return (NULL);
		}
		_strcpy(file_path, path_token);
		_strcat(file_path, "/");
		_strcat(file_path, command);
		file_path[command_len + directory_len + 1] = '\0';
		if (stat(file_path, &buff) == 0)
		{
			free(path_cp);
			return (file_path);
		}
		else
			free(file_path), path_token = _strtok(NULL, ":");
	} free(path_cp);
	if (stat(command, &buff) == 0 && (buff.st_mode & S_IXUSR))
		return (command);
	else
		return (NULL);
}

/**
 * _getenv - Get an environment variable.
 * @name: Variable to look for
 *
 * Return: The environnment variable, if not found NULL
 */

char *_getenv(const char *name)
{
	int i = 0, y, count = 0, length;
	char *copy = (char *)name;

	if (name == NULL || !name[i])
		return (NULL);

	length = _strlen(copy);
	while (*(environ + i))
	{
		y = 0;
		while (*(*(environ + i) + y) != '=')
		{
			if (*(*(environ + i) + y) == name[y])
				count++;
			y++;
		}
		if (count == length)
		{
			y++;
			return (*(environ + i) + y);
		}
		i++;
		count = 0;
	}
	return (NULL);
}
