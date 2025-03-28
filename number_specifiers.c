#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
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
/**
 * btypte: Convert int to binary.
 *  @args: A va_list containing the binary to print.
 *
 * Return: The binary characters printed.
 */
int btype(va_list args)
{
	int binary = va_arg(args, int);
	char str[32];
	int length = decimalToBinary(binary, str);

	write(1, str, length);
	return (length);
}
