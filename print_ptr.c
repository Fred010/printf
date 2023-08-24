#include "main.h"

/**
 *print_ptr - prints a string
 *@ap: argument list
 *@buff: buffer
 *@tags: flags specifier
 *@width: width specifier
 *@precision: precision specifier
 *@size: size specifier
 *
 *Return: print address
 */

int print_ptr(va_list ap, char buff[], int tags,
	int width, int precision, int size)
{
	int loc = BUFF_SIZE - 2, len = 2, initial_pad = 1;
	unsigned long arr_label;
	char more_char = 0, pad = ' ';
	char link[] = "0123456789abcdef";
	void *label = va_arg(ap, void *);

	buff[BUFF_SIZE - 1] = '\0';
	nlabel = (unsigned long) label;

	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (label == NULL)
		return (write(1, "(nil)", 5));
	while (nlabel > 0)
	{
		buff[loc--] = link[nlabel % 16];
		nlabel /= 16;
		len++;
	}

	if ((tags & F_ZERO) && !(tags & F_MINUS))
		pad = '0';
	if (tags & F_PLUS)
		more_char = '+', len++;
	else if (tags & F_SPACE)
		more_char = ' ', len++;
	loc++;
	return (ptr_print(buff, loc, len, width, tags,
		pad, initial_pad, more_char));
}
