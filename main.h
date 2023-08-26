#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define UNUSED(x)(void)(x)
#define BUFF_SIZE 1024

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_SHORT 1
#define S_LONG 2

/**
 *struct form - struct operation
 *@form: format of array
 *@func: a linked function
 */
struct form
{
	char form;
	int (*func)(va_list, char[], int, int, int, int);
};

/**
 *typedef struct form form_t - a struct operation
 *@form: struct format
 *@form_t: function link
 */
typedef struct form form_t;

int _printf(const char *format, ...);
int print_char(va_list ap, char buff[], int tags,
	int width, int precision, int size);
int print_str(va_list ap, char buff[], int tags,
	int width, int precision, int size);
int print_percent(va_list ap, char buff[], int tags,
	int width, int precision, int size);
int print_int(va_list ap, char buff[], int tags,
	int width, int precision, int size);
int print_bin(va_list ap, char buff[], int tags,
	int width, int precision, int size);
int print_uint(va_list ap, char buff[], int tags,
	int width, int precision, int size);
int print_oct(va_list ap, char buff[], int tags,
	int width, int precision, int size);
int print_hex(va_list ap, char buff[], int tags,
	int width, int precision, int size);
int print_uhex_upper(va_list ap, char buff[], int tags,
	int width, int precision, int size);
int print_hex_num(va_list ap, char link[], char buff[],
	int tags, char ch_tag, int width, int precision, int size);
int print_check(va_list ap, char buff[], int tags,
	int width, int precision, int size);
int print_ptr(va_list ap, char buff[], int tags,
	int width, int precision, int size);
int print_revstr(va_list ap, char buff[], int tags,
	int width, int precision, int size);
int print_rotstr(va_list ap, char buff[], int tags,
	int width, int precision, int size);

int print_ctrl(const char *form, int *index, va_list ap, char buff[],
	int tags, int width, int precision, int size);

int flag_fetch(const char *format, int *index);
int width_fetch(const char *format, int *index, va_list ap);
int precision_fetch(const char *format, int *index, va_list ap);
int size_fetch(const char *format, int *index);

int char_write_ctrl(char c, char buff[], int tags,
	int width, int precision, int size);
int _int_print(int neg, int index, char buff[], int tags,
	int width, int precision, int size);
int num_print(int index, char buff[], int tags, int w, int p,
	int len, char pad, char more_char);
int uint_log(int neg, int index, char buff[], int tags,
	int width, int precision, int size);
int ptr_log(char buff[], int index, int len, int width, int tags,
	char pad, char more_char, int pad_start);

int print_brew(char c);
int standardize(char cipher, char buff[], int index);
int num_find(char c);
long int _int_conversion(long int num, int size);
long int _uint_conversion(unsigned long int num, int size);


#endif /*MAIN_H */
