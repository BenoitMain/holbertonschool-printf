#include "main.h"
#include <stdio.h>
/**
 * decimalToBinary - Converts a decimal number to its binary representation.
 * @n: The decimal number to be converted.
 * @str: Pointer to a character array to store the binary string.
 *
 * Return: The length of the binary string.
 */
int decimalToBinary(int n, char *str)
{
	int binary[32];
	int i = 0, j = 0, k = 0;

	if (n == 0)
	{
		str[0] = '0';
		return (1);
	}
	while (n > 0)
	{
		binary[i] = n % 2;
		n /= 2;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
	{
		str[k++] = binary[j] + '0';
	}
	return (k);
}
