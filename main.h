#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

typedef struct print_specifiers
{
	char type;
	int (*func)(va_list args);
}print_specifiers;

int _putchar(char c);
int ft_strlen(char *str);
int find_format_type(char format_char, print_specifiers *specifiers);



int ctype(va_list args);
int stype(va_list args);
int mtype(va_list args);

int _printf(const char *format, ...);

#endif
