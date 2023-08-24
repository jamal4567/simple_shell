#include "main.h"
/**
 * _link - list with directories
 * @p: p as PATH
 * Return: adrress
 **/
link_t *_link(char *p)
{
	link_t *head = NULL;
	char *t;

	t = _strtok(p, ":");
	while (t != NULL)
	{
		head = _add_nodeint_end(&head, t);
		t = _strtok(NULL, ":");
	}
	return (head);
}
/**
 * _add_nodeint_end - add a new string to a node at the end
 * @head: head
 * @d: directories
 * Return: head
 **/
link_t *_add_nodeint_end(link_t **head, char *d)
{
	link_t *new_node;
	link_t *l_node = *head;

	new_node = malloc(sizeof(link_t));
	if (new_node == NULL)
		return (NULL);
	new_node->dir = d;
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return (*head);
	}
	else
	{
		while (l_node->next != NULL)
		{
			l_node = l_node->next;
		}
		l_node->next = new_node;
	}
	return (*head);
}
/**
 * free_list - free list
 * @head: pointer
 */
void free_list(link_t *head)
{
	link_t *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
