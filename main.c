#include "main.h"

/**
 * main - the main function of the shell
 *
 * Return: 0 always success
 */

int main(void)
{
	char *line, *path, *full_path;
	char **tokens;
	int flag, builtin_status, child_status;
	struct stat buf;

	full_path = NULL;
	signal(SIGINT, handler);
	while (1)
	{
		shell(STDIN_FILENO, buf);
		line = _getline(stdin);
		if (_strcmp(line, "\n", 1) == 0)
		{
			free(line);
			continue;
		}
		tokens = tokenizer(line);
		if (tokens[0] == NULL)
			continue;
		builtin_status = execute_builtin_command(tokens);
		if (builtin_status == 0 || builtin_status == -1)
		{
			free(tokens), free(line);
		}
		if (builtin_status == 0)
			continue;
		if (builtin_status == -1)
			_exit(EXIT_SUCCESS);
		flag = 0;
		path = _getenv("PATH");
		full_path = _which(tokens[0], full_path, path);
		if (full_path == NULL)
			full_path = tokens[0];
		else
			flag = 1;
		child_status = child(full_path, tokens);
		if (child_status == -1)
			errors(2);
		free_all(tokens, path, line, full_path, flag); }
	return (0); }


/**
 * shell - checks mode and prints prompt if interactive
 * @fd: file stream
 * @buf: buffer
**/
void shell(int fd, struct stat buf)
{
	fstat(fd, &buf);

	if (S_ISCHR(buf.st_mode))
		_puts(PROMPT);
}
