#include "main.h"

/**
 * main - the main function for our simple shell
 *
 * Return: 0(sucess) or error msg(error)
 * @ac:arguments count
 * @argv:arguments variables
 */

int main(int ac, char **argv)
{
	char *shell_prompt = "our_shell$";
	char *lineptr;
	size_t n = 0;
	ssize_t char_num;

	(void) ac;
	(void)argv;
	while (5)
	{
		printf("%s", shell_prompt);
		char_num = getline(&lineptr, &n, stdin);
		if (char_num == -1)
		{
			printf("Exit\n");
			return (-1);
		}
		printf("%s\n", lineptr);
		free(lineptr);
	}
	return (0);
}
