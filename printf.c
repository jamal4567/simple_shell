#include "main.h"
/**
* _putchar - writes a character
*
* @c: character to be write
*
* Return: 1 or -1
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
* p_char - print a character  to stdout
*
* @arguments: character to be print
*
* Return: 1
*/
int p_char(va_list arguments)
{
	_putchar(va_arg(arguments, int));
	return (1);
}
/**
* p_int - print integer
*
* @arguments: arguments
*
* Return: count
*/
int p_int(va_list arguments)
{
	long int n, n_aux, d = 1, l_aux;
	int count = 0;

	n = va_arg(arguments, int);

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
		d *= 10;
	}
	while (d > 0)
	{
		_putchar(((l_aux / d) % 10) + '0');
		count++;
		d /= 10;
	}
	return (count);
}
/**
* p_str - print string.
* @arguments:arguments.
* Return:a.
*/
int p_str(va_list arguments)
{
	char *p;
	int a;

	p = va_arg(arguments, char *);
	if (p == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	for (a = 0 ; p[a] != '\0' ; a++)
	{
	_putchar(p[a]);
	}
	return (a);
}

/**
* _printf - print
*
* @format: arguments
*
* Return: length
*/
int _printf(const char *format, ...)
{
form types[] = {
	{"c", p_char}, {"s", p_str}, {"d", p_int}, {"i", p_int}, {NULL, NULL}};
	va_list arguments;
	int pos = 0, length = 0, pos_form;

	va_start(arguments, format);
	if (!format || !format[pos])
		return (-1);
	for (; format[pos]; pos++)
	{
		if (format[pos] == '%')
		{
			if (format[pos + 1] == '\0')
				return (-1);
			if (format[pos + 1] == '%')
				_putchar(37), length++;
			else
			{
				for (pos_form = 0; types[pos_form].ch != NULL; pos_form++)
				{
					if (types[pos_form].ch[0] == format[pos + 1])
					{
						length += types[pos_form].func(arguments);
						break;
					}
				}
				if (types[pos_form].ch == NULL)
				{
					_putchar(format[pos]);
					_putchar(format[pos + 1]), length += 2;
				}
			}
			pos++;
		}
		else
			_putchar(format[pos]), length++;
	}
	va_end(arguments);
	return  (length);
}
