#include "main.h"

/**
 * *_strcpy -  copies the string pointed to by src
 * @dest: char type string
 * @src: char type string
 * Description: Copy the string pointed to by pointer `src` to
 * the buffer pointed to by `dest`
 * Return: Pointer to `dest
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strlen - checks the length of a string
 * @s: string to check
 *
 * Return: int i of the string
 */

int _strlen(char *s)
{
	int i = 0;

	while (s[i])
	{
		i++;
	}
	return (i);
}

/**
 * _strcmp - compares two strings to find out if they are exactly the same
 * @name: name supplied by user to search for
 * @variable: variable to compare against
 * @length: length of name
 * Return: 1 if strings are equal, -1 if they are not
 */
int _strcmp(char *name, char *variable, unsigned int length)
{
	unsigned int var_length;
	unsigned int i;

	var_length = _strlen(variable);
	if (var_length != length)
		return (-1);

	i = 0;
	while (name[i] != '\0' && variable[i] != '\0')
	{
		if (name[i] != variable[i])
			return (1);
		i++;
	}
	return (0);
}

/**
 * _strncmp - compares two strings
 * up to given length are the same
 * @name: name supplied by user to search for
 * @variable: variable to compare against
 * @length: length to compare up to
 * Return: 1 if strings are equal, -1 if they are not
 */
int _strncmp(char *name, char *variable, unsigned int length)
{
	unsigned int i;

	i = 0;
	while (i < length)
	{
		if (name[i] != variable[i])
			return (-1);
		i++;
	}
	return (1);
}
