#include "main.h"

/**
 * _getchar - get characters of the cmd line
 * Return: cmd line or EOF.
 **/
int _getchar(void)
{
	static unsigned char buff[BUFF_SIZE];
	static int index;
	static int count;

	index = 0;
	count = 0;
	if (index >= count)
	{
		index = 0;
		count = read(STDIN_FILENO, buff, BUFF_SIZE);
		printf("%i\n", count);
		if (count == 0)
			return (EOF);
		if (count < 0)
			return (EOF);
	}
	return (buff[index++]);
}
