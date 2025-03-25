#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
/**
 * _printf - Custom implementation of the printf function.
 * @format: The format string containing conversion specifiers.
 *
 * Return: The total number of characters printed (excluding null byte).
 */
int _printf(const char *format, ...)
{
	int i = 0, count = 0, format_index;
	print_specifiers arrayspecifiers[] = {
	    {'c', ctype}, {'%', mtype}, {'s', stype}, {'\0', NULL}};
	va_list args;

	va_start(args, format);
	if (format == NULL)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
			{
				va_end(args);
				return (-1);
			}
			format_index = find_format_type(format[i], arrayspecifiers);
			if (format_index >= 0)
			{
				count += arrayspecifiers[format_index].func(args);
			}
			else
			{
				_putchar('%');
				_putchar(format[i]);
				count += 2;
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
