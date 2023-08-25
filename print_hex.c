#include "main.h"

/**
 *print_hex - prints hexadecimal sign of a char
 *@ap: arguments list
 *@buff: buff array to handle print
 *@tags:  flag specifier
 *@width: width specifier
 *@precision: precision specifier
 *@size: size specifier
 *
 *Return: printed char
 */
int print_hex(va_list ap, char buff[],
	int tags, int width, int precision, int size)
{
	return (print_hex_num(ap, "0123456789abcdef", buff,
		tags, 'x', width, precision, size));
}
