#include "main.h"
/**
 * _strlen - length of a string
 * @str: entry
 * Return: number bytes
 **/
int _strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}
/**
 * _strcat - concat dir with 1st position array
 * @dir: dir
 * @sl: /
 * @ar: array of cmd.
 * Return: s
 **/
char *_strcat(char *dir, char *sl, char *ar)
{
	char *s = NULL;
	int line1, line2, i, j;

	line1 = _strlen(dir);
	line2 = _strlen(ar);
	s = malloc(sizeof(char) * (line1 + line2 + 2));
	if (!s)
		return (NULL);
	for (i = 0; dir[i]; i++)
		s[i] = dir[i];
	s[i] = *sl;
	j = i + 1;
	for (i = 0; ar[i]; i++)
		s[j + i] = ar[i];
	s[j + i] = '\0';
	return (s);
}
/**
 * _strtok - breaks a str
 * @s: string
 * @d: specific character
 * Return: NULL or pointer
 */
char *_strtok(char *s, char *d)
{
	int i = 0, j = 0, k = 0;
	static char *tr;

	if (!d || (!s && !tr))
		return (NULL);
	s == NULL ? s = tr : s;
	while (s[j] == ' ')
	{
		if (s[j + 1] == '\0')
			return (NULL);
		j++;
	}
	for (i = j ; s[i] != '\0' ; i++)
	{
		if (s[i] == *d)
		{
			k = 1;
			break;
		}
	}
	for (; s[i] != '\0' ; i++)
		if (s[i] != d[0])
			break;
		else if (s[i + 1] == '\0')
		{
			k = 0, s[i] = '\0';
			break;
		}
		else
			s[i] = '\0';
	if (k == 0)
	{
		tr = NULL;
		return (s + j);
	}
	if (s + i)
		tr = s + i;
	else
		tr = NULL;
	return (s + j);
}
/**
 * *_strcpy - copies the string
 * @src: source pointer
 * @dest: destination ptr
 * Return: a char pointer
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0, j = 0;

	while (src[i] != '\0')
		i++;
	while (j < i)
	{
		dest[j] = src[j];
		j++;
	}
	for (; j <= i ; j++)
	{
		dest[j] = '\0';
	}
	return (dest);
}
