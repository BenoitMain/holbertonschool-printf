#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
/**
 * ctype - Prints character type
 * @args: A va_list containing the character to print
 *
 * Return: 1.
 */
int ctype(va_list args)
{
	char letter = va_arg(args, int);

	write(1, &letter, 1);
	return (1);
}
/**
 * mtype - Prints a character from a variadic argument list
 * @args: The variadic argument list containing the character
 *
 * Return: 1.
 */
int mtype(va_list args)
{
	(void)args;
	_putchar('%');
	return (1);
}
/**
 * stype - Prints string type
 * @args: A va_list containing the string to print
 *
 * Return: lenght.
 */
int stype(va_list args)
{
	char *str = va_arg(args, char *);
	char *nil_str = "(null)";
	int lenght;

	if (str == NULL)
	{
		write(1, nil_str, ft_strlen(nil_str));
		return (ft_strlen(nil_str));
	}
	lenght = ft_strlen(str);
	write(1, str, lenght);
	return (lenght);
}
/**
 * dtype - Prints an integer as a decimal number.
 * @args: A va_list containing the integer to print.
 *
 * Return: The number of characters printed.
 */
int dtype(va_list args)
{
	int number = va_arg(args, int);
	char str[20];
	int lenght = convert_to_string(number, str);

	write(1, str, lenght);
	return (lenght);
}
/**
 ** itype - Prints an integer.
 * @args: A va_list containing the integer to print.
 *
 * Return: The number of characters printed.
 */
int itype(va_list args)
{
	int number = va_arg(args, int);
	char str[20];
	int length = convert_to_string(number, str);

	write(1, str, length);
	return (length);
}
