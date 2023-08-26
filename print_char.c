#include "main.h"

/**
 * print_char - prints a character
 * @ap: argument list
 * @buff: buffer array
 * @tags: flags
 * @width: width
 * @precision: precision
 * @size: size
 *
 * Return: print char count
 */

int print_char(va_list ap, char buff[], int tags,
		int width, int precision, int size)
{
	char ch = va_arg(ap, int);

	return (char_write_ctrl(ch, buff, tags, width, precision, size));
}
