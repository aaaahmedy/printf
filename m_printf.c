#include "main.h"
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
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
* numlen - calculates the lentgh of a number.
* @number: the number given.
* Return: the length.
*/
int num_len(int number)
{
	int length = 0;

	while (number != 0)
	{
		number /= 10;
		length++;
	}
	return (length);
}
/**
* _int_value - handling with int (%d) and (%i).
* @number: the giving integer.
* Return: the number printed.
*/
int _int_value(int number)
{
	char *string;
	int len = 0, i;

	if (number == 0)
	{
		_putchar ('0');
		return (1);
	}
	if (number < 0)
	{
		_putchar('-');
		number = -number;
	}
	len = num_len(number);
	string = (char *)malloc(sizeof(char) * (len + 1));
	if (string == NULL)
		return (-1);
	for (i = len - 1; i >= 0; i--)
	{
		string[i] = '0' + (number % 10);
		number /= 10;
	}
	string[len] = '\0';
	write(1, string, len);
	free(string);
	return (len);
}
/**
* _printf - produces output according to a format.
* @format: the format specifier.
* Return: the number of characters printed.
*/
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0, i = 0, value = 0;
	char *string;

	va_start(args, format);
	if (format == NULL)
		return (-1);
	while (*(format + i) != '\0')
	{
		if (*(format + i) == '%')
		{
			i++;
			switch (*(format + i))
			{
			case 'c':
				value = va_arg(args, int);
				write(1, &value, 1);
				count++;
				break;
			case 's':
				string = va_arg(args, char *);
				value = _string_type(string);
				count += value;
				break;
			case 'd':
				value = va_arg(args, int);
				count += _int_value(value);
				break;
			case 'i':
				value = va_arg(args, int);
				count += _int_value(value);
				break;
			default:
				_putchar('%');
				_putchar(*(format + i));
				count += 2;
				break;
			}
		}
		else
		{
			_putchar (*(format + i));
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
