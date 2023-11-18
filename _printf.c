#include "main.h"
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character
 * Return: 1 (true).
 * On error, -1 is returned, and errno is set appropriately.
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _string_type - Handle variable type string.
 * @strg: String entered by the user
 *  Return: number characters entered
*/

int _string_type(char *strg)
{
	int num_char = 0;

	if (strg == NULL)
	{
		strg = "(null)";
		write(1, strg, 6);
		return (6);
	}
	else
	{
		num_char = strlen(strg);
		write(1, strg, num_char);
		return (num_char);
	}
}

/**
* _printf - produces output according to a format.
* @format: the format specifier to arg .
* Return: the number of characters printed.
*/

int _printf(const char *format, ...)
{
	va_list argms;
	int i = 0, num_c = 0, count = 0;
	char *strg;

	va_start(argms, format);
	if (format == NULL)
		return (-1);
	while (*(format + i) != '\0')
	{
		if (*(format + i) == '%')
		{
			i++;
			if (*(format + i) == 'c')
			{
				num_c = va_arg(argms, int);
				write(1, &num_c, 1);
				count++;
			}
			else if (*(format + i) == 'c')
			{
				strg = va_arg(argms, char *);
				num_c = _string_type(strg);
				count += num_c;
			}
			else
			{
				_putchar('%');
				count++;
			}
		}
		else
		{
			_putchar(*(format + i));
			count++;
		}
		i++;
	}
	va_end(argms);

	return (count);
}
