#include "main.h"

/**
 *print_uhex_upper - prints upper hexadecimal sign of char
 *@ap: arguments list
 *@buff: buff array
 *@tags: flag specifier
 *@width: width specifier
 *@precision: precision specifier
 *@size: size specifier
 *Return: printed char
 */

int print_uhex_upper(va_list ap, char buff[],
	int tags, int width, int precision, int size)
{
	return (print_hex_num(ap, "0123456789ABCDEF", buff,
		tags, 'X', width, precision, size));
}
