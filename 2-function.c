#include "main.h"
/**
 * check_path - check for argumnt
 * @arm:arguments
 * Return: arm or NULL
 */
char *check_path(char *arm)
{
	if (access(arm, X_OK) == 0)
		return (arm);
	return (NULL);
}

/**
 * execute_command - check for argumnts
 * @arm:arguments
 * Return: arm or NULL
 */
char *execute_command(char *arm)
{
	char *p = NULL;
	link_t *head = NULL;
	char *b = NULL;

	p = _get_env("PATH");
	head = _link(p);
	b = _which(&head, arm);
	if (b != NULL)
	{
		free(p),
		free_list(head);
		return (b);
	}
	free(p);
	free_list(head);
	return (NULL);
}
