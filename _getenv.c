#include "main.h"

/**
 * _getenv - gets the environment variable
 * @name : name of environment variable
 * Return: pointer to environment variable or NULL if fail
 */

char *_getenv(const char *name)
{
	char **environ_cp;
	char *variable, *value, *path;
	int compare;
	unsigned int path_length, environ_length, length, i;

	environ_length = 0;
	while (environ[environ_length] != NULL)
		environ_length++;
	environ_cp = NULL;
	environ_cp = copy_env(environ_cp, environ_length);

	length = _strlen((char *)name);
	i = 0;
	while (environ_cp[i] != NULL)
	{
		variable = environ_cp[i];
		compare = _strncmp((char *)name, variable, length);
		if (compare == 1)
		{
			value = strtok(variable, "=");
			value = strtok(NULL, "\n ");
			if (*value == '\0')
			{
				errors(4);
				exit(EXIT_FAILURE);
			}
			path_length = _strlen(value);
			path = malloc(sizeof(char) * path_length + 1);
			if (path == NULL)
			{
				errors(3);
				return (NULL);
			}
			path = _strcpy(path, value);
			free_array(environ_cp, environ_length);
			return (path);
		}
		i++;
	}
	return (NULL);
}

/**
 * copy_env - copies the environment variable
 * @environ_cp: pointer to environment variable copy
 * @environ_length: of environment variable lenghth
 * Return: environ copy
 */
char **copy_env(char **environ_cp, unsigned int environ_length)
{
	char *variable;
	unsigned int variable_length;
	unsigned int i;

	environ_cp = malloc(sizeof(char **) * (environ_length));
	if (environ_cp == NULL)
	{
		errors(3);
		return (NULL);
	}

	i = 0;
	while (i < environ_length)
	{
		variable = environ[i];
		variable_length = _strlen(variable);

		environ_cp[i] = malloc(sizeof(char) * variable_length + 1);
		if (environ_cp[i] == NULL)
		{
			errors(3);
			return (NULL);
		}
		_strcpy(environ_cp[i], environ[i]);
		i++;
	}

	return (environ_cp);
}

/**
 * free_array - free array
 * @array: array pointer to free
 * @len: length of double pointer
 *
 * Return: void
 */
void free_array(char **array, unsigned int len)
{
	unsigned int i;

	i = 0;
	while (i < len)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
