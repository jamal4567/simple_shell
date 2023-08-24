#include "holberton.h"
/**
 * _myexit - check command
 * @line: command
 * Return: 0 or 1
 **/
int _myexit(char *line)
{
	char *exit_line = "exit";
	int i = 0;
	int len = _strlen(line);

	if (len == 4)
	{
		while (exit_line[i])
		{
			if (exit_line[i] != line[i])
				return (1);
			i++;
		}
		free(line);
		return (0);
	}
	return (1);
}
/**
 * signal_c - Ignore input
 * @sign:parameter
 *
 **/
void signal_c(int sign)
{
	signal(sign, SIG_IGN);
	write(STDOUT_FILENO, "\n#cisfun$ ", 11);
	signal(SIGINT, signal_c);
}
/**
 * _myenv - environment variables
 *
 * @line: command
 * @counter: number of arguments
 * @argv: arguments
 * @env: variables
 * Return: 0 or 1
 **/
int _myenv(char *line, int counter, char **argv, char **env)
{
	char *env_line = "env";
	int i = 0;
	int len = _strlen(line);

	if (len == 3)
	{
		while (env_line[i])
		{
			if (env_line[i] != line[i])
				return (1);
			i++;
		}
		if (env)
		{
			for (i = 0; env[i] != NULL; i++)
				_printf("%s\n", env[i]);
			free(line);
			return (0);
		}
		else
		{
			_printf("%s: %d: env: not found\n", argv[0], counter);
			return (127);
		}
	}
	return (1);
}
