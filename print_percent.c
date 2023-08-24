#include "main.h"

/**
 * print_percent - prints a string
 * @ap: argument list
 * @buff: buffer
 * @tags: flags specifier
 * @width: width specifier
 * @precision: precision specifier
 * @size: size specifier
 *
 * Return: print percentage count
 */

int print_percent(va_list ap, char buff[], int tags,
		int width, int precision, int size)
{
	UNUSED(ap);
	UNUSED(buff);
	UNUSED(tags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	return (write(1, "%%", 1));
}
