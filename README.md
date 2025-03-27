<div align="center"><img src="https://github.com/ksyv/holbertonschool-web_front_end/blob/main/baniere_holberton.png"></div>

# Printf Project 🎉

## Description 🧐

This project is an implementation of the `printf` function in C 📚. It aims to replicate the functionality of the standard C library `printf` function, formatting and printing a series of characters and values to the standard output stream 💻.

## Resources

- [Secrets of printf](https://intranet.hbtn.io/rltoken/5XDYxBZJUAMfLWdifnFnGQ) 🤫
- [Group Projects concept page](https://intranet.hbtn.io/concepts/111) 👥
- [Flowcharts concept page](https://intranet.hbtn.io/concepts/130) 📈

## Requirements

### General

- Allowed editors: vi, vim, emacs ✏️
- All files will be compiled on Ubuntu 20.04 LTS using gcc, with options `-Wall -Werror -Wextra -pedantic -std=gnu89` 🛠️
- All files should end with a new line 📄
- Code should use the Betty style 💅
- No global variables allowed 🚫
- No more than 5 functions per file 📝
- All function prototypes should be included in the header file `main.h` 📁
- Header files should be include guarded 🔒

### Compilation

The code will be compiled this way:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c
```

## Authorized Functions and Macros

- write (man 2 write) 📝
- malloc (man 3 malloc) 📈
- free (man 3 free) 🚮
- va_start (man 3 va_start) 🔑
- va_end (man 3 va_end) 🔒
- va_copy (man 3 va_copy) 📋
- va_arg (man 3 va_arg) 📝

## Project Structure

- `main.h` : Header file containing all function prototypes 📁
- `*.c` : Implementation files 💻
- `README.md` : This file, containing project information and instructions 📄

## GitHub Repository

One project repository per group 👥. Cloning/forking a project repository with the same name before the second deadline may result in a 0% score ⚠️.

## Important Notes

- Do not push any .c files containing a `main` function in the root directory of your project. You can have a `test` folder containing all your tests files including `main` functions 🚫
- Our main files will include your main header file (`main.h`): `#include main.h`
- You might want to look at the gcc flag `-Wno-format` when testing with your `_printf` and the standard `printf` 🧪
- We strongly encourage you to work all together on a set of tests 🤝
- If the task does not specify what to do with an edge case, do the same as `printf` 🔍

## Testing :chart_rising:

When testing with your `_printf` and the standard `printf`, you might want to use the gcc flag `-Wno-format` 🤔.

```bash
alex@ubuntu:~/c/printf$ cat main.c 
#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");
    return (0);
}
alex@ubuntu:~/c/printf$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c
alex@ubuntu:~/c/printf$ ./printf
Let's try to printf a simple sentence.
Let's try to printf a simple sentence.
Length:[39, 39]
Length:[39, 39]
Negative:[-762534]
Negative:[-762534]
Unsigned:[2147484671]
Unsigned:[2147484671]
Unsigned octal:[20000001777]
Unsigned octal:[20000001777]
Unsigned hexadecimal:[800003ff, 800003FF]
Unsigned hexadecimal:[800003ff, 800003FF]
Character:[H]
Character:[H]
String:[I am a string !]
String:[I am a string !]
Address:[0x7ffe637541f0]
Address:[0x7ffe637541f0]
Percent:[%]
Percent:[%]
Len:[12]
Len:[12]
Unknown:[%r]
Unknown:[%r]
alex@ubuntu:~/c/printf$
```
Man page _printf  :mag:
```bash
.TH _PRINTF 3 "27 mars 2025" "Version 1.0" "Bibliothèque personnalisée"
.SH NOM
_printf \- Implémentation personnalisée de printf avec gestion basique des formats
.SH SYNOPSIS
.B #include "main.h"
.PP
.B int _printf(const char *format, ...);
.SH DESCRIPTION
La fonction \fB_printf()\fR imprime des données formatées sur la sortie standard. Elle utilise une structure de pointeurs de fonctions pour gérer les différents spécificateurs de format.
Comportements clés :
.IP \[bu] 3
Gestion des conversions : c, s, %, d, i
.IP \[bu]
Les chaines NULL sont affichées comme "(null)"
.IP \[bu]
Les spécificateurs inconnus sont imprimés littéralement (ex: %r → %r)
.IP \[bu]
Buffer fixe de 20 caractères pour les conversions numériques
Structure interne :
.TP
.B print_specifiers
Tableau de structures liant les caractères de format à leurs handlers :
.RS
.IP \[bu] 3
%c → ctype()
.IP \[bu]
%s → stype()
.IP \[bu]
%% → mtype()
.IP \[bu]
%d/%i → dtype()/itype()
.RE
.SH VALEUR DE RETOUR
Nombre total de caractères imprimés. Retourne -1 si :
.RS
.IP \[bu] 3
Le format est NULL
.IP \[bu]
Un spécificateur est incomplet (ex: "%" en fin de chaine)
.RE
.SH FONCTIONS INTERNES
.TP
.B ctype()
Imprime un caractère via write()
.TP
.B stype()
Gère les chaines avec vérification de NULL
.TP
.B dtype()/itype()
Convertit les entiers avec convert_to_string()
.TP
.B mtype()
Imprime le caractère '%' littéral
.SH EXEMPLES
Sortie pour %d et %i identique :
.nf
_printf("%d vs %i", 42, -42); → "42 vs -42"
.fi
Gestion des erreurs :
.nf
_printf("Test %"); → Retourne -1
.fi
.SH BOGUES
.IP \[bu] 3
Taille fixe du buffer pour les nombres (risque de dépassement)
.IP \[bu]
Pas de gestion des nombres longs
.IP \[bu]
Performance non optimisée pour les grandes sorties
.SH [BenoitMain-Boubouche1709]
.SH VOIR AUSSI
.BR printf(3), write(2), stdarg(3)

```
Flowchart :sparkles:

![mon diagrame](https://raw.githubusercontent.com/BenoitMain/holbertonschool-printf/refs/heads/main/Flow%20Chart%20_printf.drawio.svg)


Authors :``` BenoitMain ```
