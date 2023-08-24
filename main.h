#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024


int _printf(const char *format, ...);
int print_char(va_list ap, char buff[], int tags,
	int width, int precision, int size);
int print_str(va_list ap, char buff[], int tags,
	int width, int precision, int size);
int print_percent(va_list ap, char buff[], int tags,
	int width, int precision, int size);

#endif /* MAIN_H */
