#include "main.h"
/**
* _putchar - writes the character c.
* @c: The char to print.
* Return: 1, -1 , errno.
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
* p_char - writes the character c
* @args: The char to print
* Return: int.
*/
int p_char(va_list args)
{
	_putchar(va_arg(args, int));
	return (1);
}
/**
* p_int - print int.
* @args: arguments
* Return: Int.
*/
int p_int(va_list args)
{
	long int n, n_aux, a = 1, l_aux;
	int count = 0;

	n = va_arg(args, int);

	if (n < 0)
	{
		n_aux = -n;
		_putchar('-');
		count++;
	}
	else
		n_aux = n;
	l_aux = n_aux;
	while (n_aux > 9)
	{
		n_aux = n_aux / 10;
		a *= 10;
	}
	while (a > 0)
	{
		_putchar(((l_aux / a) % 10) + 48);
		count++;
		a /= 10;
	}
	return (count);
}
/**
* p_str - print string.
* @args: arguments number.
* Return: Int.
*/
int p_str(va_list args)
{
	char *ptr;
	int i = 0;

	ptr = va_arg(args, char *);
	if (ptr == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (ptr[i] != '\0')
	{
	_putchar(ptr[i]);
	i++;
	}
	return (i);
}

/**
* _printf - print c,s,f,u,i,d
* @frmt: arguments
* Return: length
*/
int _printf(const char *frmt, ...)
{
form types[] = {
	{"c", p_char}, {"s", p_str}, {"d", p_int}, {"i", p_int}, {NULL, NULL}};
	va_list args;
	int pos = 0, len = 0, pos_form;

	va_start(args, frmt);
	if (!frmt || !frmt[pos])
		return (-1);
	for (; frmt[pos]; pos++)
	{
		if (frmt[pos] == '%')
		{
			if (frmt[pos + 1] == '\0')
				return (-1);
			if (frmt[pos + 1] == '%')
				_putchar(37), len++;
			else
			{
				for (pos_form = 0; types[pos_form].ch != NULL; pos_form++)
				{
					if (types[pos_form].ch[0] == frmt[pos + 1])
					{
						len += types[pos_form].func(args);
						break;
					}
				}
				if (types[pos_form].ch == NULL)
				{
					_putchar(frmt[pos]);
					_putchar(frmt[pos + 1]), len += 2;
				}
			}
			pos++;
		}
		else
			_putchar(frmt[pos]), len++;
	}
	va_end(args);
	return (len);
}
