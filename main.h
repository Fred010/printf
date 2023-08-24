#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)

/**
 * struct form_opr - checks format type
 * @opr: specifier type
 * @fn: function link
 */

typedef struct form_opr
{
	char *opr;
	int (*fn)();
} form_t;

int _putchar(char c);
int _strlen(char *str);
int _printf(const char *format, ...);
int print_char(va_list roll);
int print_str(va_list roll);
int print_int(va_list roll);
int print_strexe(va_list roll);
int print_ptr(va_list roll);
int print_revstr(va_list roll);
int print_rotstr(va_list roll);


#endif /* MAIN_H */
