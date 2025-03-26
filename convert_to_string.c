#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
/**
 * convert_to_string - Converts an integer to a string representation.
 * @num: The integer to be converted.
 * @str: The buffer where the resulting string will be stored.
 *
 * Return: The length of the resulting string.
 */
int convert_to_string(int num, char *str)
{
	int i = 0, is_negative = 0, start, end;
	unsigned int n;
	char temp;

	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (1);
	}
	if (num < 0)
	{
		is_negative = 1;
		n = -num;
	}
	else
	{
		n = num;
	}
	while (n > 0)
	{
		str[i++] = (n % 10) + '0';
		n /= 10;
	}
	if (is_negative)
	{
		str[i++] = '-';
	}
	str[i] = '\0';
	start = 0;
	end = i - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
	return (i);
}
