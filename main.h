#ifndef main_h
#define main_h

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <stdarg.h>
#include <limits.h>
#ifndef BUFF_SIZE
#define BUFF_SIZE 300
#endif

extern char **environ;

/**
 * struct link - node that contains the directories
 * @dir: directory
 * @next: position to change the node
 */
typedef struct link
{char *dir;
struct link *next;
} link_t;
/**
* struct formats - struct formats
* @ch: pointer to firts element.
* @func: The function associated.
*/
typedef struct formats
	{
		char *ch;
		int (*func)();
	} form;

char *_get_env(const char *nm);
ssize_t _get_lin(char **bufferline, size_t *s, FILE *st);
char **_splitline_(char *c_lin);
int _exe_proc(char **arm, char **ar, int count);
char *_which(link_t **head, char *av);
char *_strcpy(char *dest, char *src);
char *_strtok(char *s, char *d);
char *_strcat(char *dir, char *sl, char *ar);
int _strlen(char *str);
link_t *_link(char *p);
void free_list(link_t *head);
link_t *_add_nodeint_end(link_t **head, char *d);
int _putchar(char c);
int p_char(va_list args);
int p_int(va_list args);
int p_str(va_list args);
int _printf(const char *frmt, ...);
char *check_path(char *arm);
char *execute_command(char *arm);
int main(int __attribute__((unused))ac, char **ar, char **env);
int _exit(char *l);
int _env(char *l, int count, char **ar, char **env);
void _signal(int sg);
int _getchar(void);
#endif
