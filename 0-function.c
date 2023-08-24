#include "main.h"
/**
 * _get_env - get the env
 * @nm: parameter
 * Return: NULL or pointer
 */
char *_get_env(const char *nm)
{
	int i = 0, j = 0;
	char *a;
	char *tmp;

	while (environ[i] != NULL)
	{
		while (nm[j] == environ[i][j] && nm[j] != '\0')
		{
			if (nm[j + 1] == '\0')
			{
				a = &environ[i][j + 2];
				tmp = malloc(sizeof(char) * _strlen(a) + 1);

				if (!tmp)
					return (NULL);

				tmp = _strcpy(tmp, a);
				return (tmp);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
/**
 * _get_lin - command from the prompt
 * @bufferline: buffer line.
 * @s: s of the buffer lines.
 * @st: file stream.
 * Return: count
 **/
ssize_t _get_lin(char **bufferline, size_t *s, FILE *st)
{
	size_t count = 0;
	size_t alloc = 1024;
	char c;

	if (!bufferline || !s || !st)
		return (-1);
	if (*bufferline == NULL)
	{
		*bufferline = malloc(alloc);
		if (!(*bufferline))
			return (-1);
	}
	while ((c = _getchar()) != EOF)
	{
		if (c == '\n')
		{
			count++;
			break;
		}
		count++;
		(*bufferline)[count - 1] = c;
	}
	if (c == EOF)
	{
		return (-1);
	}
	(*bufferline)[count] = '\0';
	return (count);
}
/**
* _splitline_ - command from the prompt
* @c_lin: command line
* Return: a pointer
**/
char **_splitline_(char *c_lin)
{
	char **str, *w;
	int st = 100;
	int p = 0;

	str = malloc(sizeof(char *) * st);
	if (str == NULL)
		exit(EXIT_FAILURE);
	w = _strtok(c_lin, " ");
	while (w != NULL)
	{
		str[p++] = w;
		w = _strtok(NULL, " ");
	}
	str[p] = NULL;
	return (str);
}
/**
 * _exe_proc - execute process function
 * @arm: arguments from command_line
 * @ar: string of arguments
 * @count: number of ecution processes
 * Return: 0 (Success) -1 (Failed)
 **/
int _exe_proc(char **arm, char **ar, int count)
{
	pid_t child_process;
	int status, status_output = 0;
	char *buff = NULL, *command_path = NULL;

	command_path = check_path(arm[0]);
	if (command_path == NULL)
	{
		buff = execute_command(arm[0]);
		if (buff == NULL)
		{
			_printf("%s: %d: %s: not found\n", ar[0], count, arm[0]);
			free(buff);
			return (1);
		}
	}
	child_process = fork();
	if (child_process < 0)
		exit(errno);
	else if (child_process == 0)
	{
		if (command_path != NULL)
		{
			if (execve(command_path, arm, environ) == -1)
				exit(errno);
		}
		if (execve(buff, arm, environ) == -1)
			exit(errno);
	}

	wait(&status);
	if (WIFEXITED(status))
		status_output = WEXITSTATUS(status);
	free(buff);

	return (status_output);
}
/**
 * _which - search ofr a command in the directories
 * @head: head
 * @av: arguments
 * Return: path of a command or nil
 **/
char *_which(link_t **head, char *av)
{
	link_t *pusher = *head;
	char *buff;

	if (av[0] == '.' || av[0] == '/')
	{
		if (access(av, X_OK) == 0)
			return (av);
	}

	while (pusher)
	{
		buff = _strcat(pusher->dir, "/", av);
		if (access(buff, X_OK) == 0)
		{
			return (buff);
		}
		free(buff);
		pusher = pusher->next;
	}
	return (NULL);
}
