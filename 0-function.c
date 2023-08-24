#include "main.h"
/**
 * _getenv - find the env
 * @name: variable
 * Return: NULL or pointer
 */
char *_getenv(const char *name)
{
	int i;
	int j;
	char *a;
	char *copy;

	for (i = 0 ; environ[i] != NULL ; i++)
	{
		for (j = 0 ; name[j] == environ[i][j] && name[j] != '\0' ; j++)
		{
			if (name[j + 1] == '\0')
			{
				a = &environ[i][j + 2];
				copy = malloc(sizeof(char) * _strlen(a) + 1);

				if (!copy)
					return (NULL);

				copy = _strcpy(copy, a);
				return (copy);
			}
		}
	}
	return (NULL);
}
/**
 * _getline - get line command line
 *
 * @bufline: command
 * @size: size of the command
 * @std: file stream
 *
 * Return: number of bytes
 **/
ssize_t _getline(char **bufline, size_t *size, FILE *std)
{
	size_t count = 0;
	size_t alloc = 1024;
	char c;

	if (!bufline || !size || !std)
		return (-1);

	if (*bufline == NULL)
	{
		*bufline = malloc(alloc);
		if (!(*bufline))
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
		(*bufline)[count - 1] = c;
	}
	if (c == EOF)
	{
		return (-1);
	}
	(*bufline)[count] = '\0';
	return (count);
}
/**
* splitline - get line command line
* @command_line: command.
* Return: a pointer
**/
char **splitline(char *command_line)
{
	char **ptrstr;
	int size = 100;
	int position = 0;
	char *word;

	ptrstr = malloc(sizeof(char *) * size);
	if (ptrstr == NULL)
		exit(EXIT_FAILURE);
	word = _strtok(command_line, " ");
	while (word != NULL)
	{
		ptrstr[position++] = word;
		word = _strtok(NULL, " ");
	}
	ptrstr[position] = NULL;
	return (ptrstr);
}
/**
 * execute_process - execute process function
 *
 * @argm: arguments
 * @argv: strings
 * @counter: number of exeution processes
 *
 * Return: 0 or -1
 **/
int execute_process(char **argm, char **argv, int counter)
{
	pid_t child_process;
	int status, status_output = 0;
	char *buffer = NULL, *command_path = NULL;

	command_path = check_path(argm[0]);
	if (command_path == NULL)
	{
		buffer = execute_command(argm[0]);
		if (buffer == NULL)
		{
			_printf("%s: %d: %s: not found\n", argv[0], counter, argm[0]);
			free(buffer);
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
			if (execve(command_path, argm, environ) == -1)
				exit(errno);
		}
		if (execve(buffer, argm, environ) == -1)
			exit(errno);
	}

	wait(&status);
	if (WIFEXITED(status))
		status_output = WEXITSTATUS(status);
	free(buffer);

	return (status_output);
}
/**
 * _which - search for a commands
 *
 * @head: head
 * @av: arguments
 *
 * Return: path of a command
 **/
char *_which(link_t **head, char *av)
{
	link_t *pusher = *head;
	char *buffer;

	if (av[0] == '.' || av[0] == '/')
	{
		if (access(av, X_OK) == 0)
			return (av);
	}

	while (pusher)
	{
		buffer = _strcat(pusher->dir, "/", av);
		if (access(buffer, X_OK) == 0)
		{
			return (buffer);
		}
		free(buffer);
		pusher = pusher->next;
	}
	return (NULL);
}
