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
 * *_strncat - concatenates @src to @dest
 * @src: the source string to append to @dest
 * @dest: the destiation string to be concatenated upon
 * @n: number of source to be taken
 * Return:pointer to the resulting string
 */

char *_strncat(char *dest, char *src, int n)
{
	int i = 0;
	int j;

	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (j < n && src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
	j++;
	}
	if  (i < n)
	{
	dest[i] = '\0';
	}

	return (dest);
}

/**
 * _strcmp - a function that compares two strings
 * @s1 : first string
 * @s2 : second string
 * * Return: If str1 < str2, the negative difference of
 * the first unmatched characters.
 * If s1 == s2, 0.
 * If s1 > s2, the positive difference of
 * the first unmatched characters.
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
	if (s1[i] != s2[i])
	{
		return (s1[i] - s2[i]);
	}
	}
		return (0);
}
