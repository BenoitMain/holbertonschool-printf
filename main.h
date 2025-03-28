#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

typedef struct print_specifiers
{
	char type;
	int (*func)(va_list args);
} print_specifiers;

int _putchar(char c);
int ft_strlen(char *str);
int convert_to_string(int num, char *str);
int find_format_type(char format_char, print_specifiers *specifiers);
int decimalToBinary(int n, char *str);

int ctype(va_list args);
int stype(va_list args);
int mtype(va_list args);
int dtype(va_list args);
int itype(va_list args);
int btype(va_list args);

int _printf(const char *format, ...);

#endif
