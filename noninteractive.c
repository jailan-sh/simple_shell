#include "main.h"

/**
 * noninteractive - oninteractive mode
 *
 * Return: void
 */

void noninteractive(void)
{
	char *line, *path, *full_path;
	char **tokens;
	int flag, buil_run, execute;

	full_path = NULL;
	while (1)
	{
		line = _getline(stdin);
		if (_strcmp(line, "\n", 1) == 0)
		{
			free(line);
			continue;
		}
		tokens = tokenizer(line);
		if (tokens[0] == NULL)
			continue;
		buil_run = execute_builtin_command(tokens);
		if (buil_run == 0 || buil_run == -1)
		{
			free(tokens), free(line);
		}
		if (buil_run == 0)
			continue;
		if (buil_run == -1)
			_exit(EXIT_SUCCESS);
		flag = 0;
		path = _getenv("PATH");
		full_path = _which(tokens[0], full_path, path);
		if (full_path == NULL)
			full_path = tokens[0];
		else
			flag = 1;
		execute = child(full_path, tokens);
		if (execute == -1)
			errors(2);
		free_all(tokens, path, line, full_path, flag); }
}
