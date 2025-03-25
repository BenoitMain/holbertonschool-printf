#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
/**
 * ft_strlen -Calculates the length of a string.
 * @str: The string whose length is to be determined.
 *
 *  Return: The length of the string, or 0 if str is NULL.
 */
int ft_strlen(char *str)
{
	int length = 0;

	if (str == NULL)
		return (0);

	while (str[length] != '\0')
	{
		length++;
	}

	return (length);
}
