#include "main.h"
/**
 * check_path - check argument if already path
 * @argm: argument
 * Return: argm or NULL
 */
char *check_path(char *argm)
{
	if (access(argm, X_OK) == 0)
		return (argm);
	return (NULL);
}

/**
 * execute_command - check argument if already path
 * @argm: argument
 * Return: argm or NULL
 */
char *execute_command(char *argm)
{
	char *path = NULL;
	link_t *head = NULL;
	char *buffer = NULL;

	path = _getenv("PATH");
	head = _link(path);
	buffer = _which(&head, argm);
	if (buffer != NULL)
	{
		free(path),
		free_list(head);
		return (buffer);
	}
	free(path);
	free_list(head);
	return (NULL);
}
