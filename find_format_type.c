#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
/**
 * find_format_type - Finds the index of a format specifier in the array.
 * @format_char: The format specifier character to search for.
 * @specifiers: The array of format specifiers and corresponding functions.
 *
 * Return: The index of the format specifier in the array, or -1 if not found.
 */
int find_format_type(char format_char, print_specifiers *specifiers)
{
	int j = 0;

	while (specifiers[j].type != '\0')
	{
		if (format_char == specifiers[j].type)
		{
			return (j);
		}
		j++;
	}
	return (-1);
}
