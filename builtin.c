#include "main.h"
/**
 * exit - check command to exit
 * @l: command
 * Return: 0 or 1
 **/
int exit(char *l)
{
	char *exit_l = "exit";
	int i;
	int length = _strlen(l);

	if (length == 4)
	{
		for (i = 0; exit_l[i]; i++)
		{
			if (exit_l[i] != l[i])
				return (1);
		}
		free(l);
		return (0);
	}
	return (1);
}
/**
 * _env - print the environment variables separated.
 * @l: The command line.
 * @count: number of entry arguments
 * @ar: entry arguments from main
 * @env: enviroment variables
 * Return: 0 if succes or 1 if fails. 127 if env not found
 **/
int _env(char *l, int count, char **ar, char **env)
{
	char *env_l = "env";
	int i = 0;
	int length = _strlen(l);

	if (length == 3)
	{
		while (env_l[i])
		{
			if (env_l[i] != l[i])
				return (1);
			i++;
		}
		if (env)
		{
			for (i = 0; env[i] != NULL; i++)
				_printf("%s\n", env[i]);
			free(l);
			return (0);
		}
		else
		{
			_printf("%s: %d: env: not found\n", ar[0], count);
			return (127);
		}
	}
	return (1);
}
/**
 * _signal - Ignore input signal
 * @sg: parameter
 **/
void _signal(int sg)
{
	signal(sg, SIG_IGN);
	write(STDOUT_FILENO, "\n#cisfun$ ", 11);
	signal(SIGINT, _signal);
}
