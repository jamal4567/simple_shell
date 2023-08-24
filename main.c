#include "main.h"
/**
 * main - Entry point for shell
 * @ac: Number of arguments
 * @ar: string of arguments
 * @env: environemet variable
 * Return: 0 (Return value)
 */
int main(int __attribute__((unused))ac, char **ar, char **env)
{
	int status_output = 0, read = 1, count = 0;

	while (read)
	{
		char *cmd_line = NULL, **arm = NULL;
		size_t line_size = 0;

		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "#cisfun$ ", 10);
		signal(SIGINT, _signal);
		read = _get_lin(&cmd_line, &line_size, stdin);
		if (read < 0)
		{
			free(cmd_line);
			exit(status_output);
		}
		if (read == 1)
		{
			free(cmd_line);
			continue;
		}
		if (read != EOF)
		{
			count++;
			_strtok(cmd_line, "\n");
			if (_exit(cmd_line) == 0)
				return (status_output);
			if (_env(cmd_line, count, ar, env) == 0)
				continue;
			arm = _splitline_(cmd_line);
			if (arm[0] == NULL)
			{
				free(cmd_line), free(arm);
				continue;
			}
			status_output = _exe_proc(arm, ar, count);
		}
		free(cmd_line), free(arm);
	}
	return (status_output);
}
