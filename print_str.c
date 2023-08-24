#include "main.h"

/**
 * print_str - prints a string
 * @ap: argument list
 * @buff: buffer
 * @tags: flags specifier
 * @width: width specifier
 * @precision: precision specifier
 * @size: size specifier
 *
 * Return: print str count
 */

int print_str(va_list ap, char buff[], int tags,
		int width, int precision, int size)
{
	int strlen = 0, n;
	char *str = va_arg(ap, char *);

	UNUSED(buff);
	UNUSED(tags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
		{
			str = "   ";
		}
	}
	while (str[strlen] != '\0')
		strlen++;
	if (precision >= 0 && precision < strlen)
		strlen = precision;
	if (width > strlen)
	{
		if (tags & F_MINUS)
		{
			write(1, &str[0], strlen);
			for (n = width - strlen; n > 0; n--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (n = width - strlen; n > 0; n--)
				write(1, " ", 1);
			write(1, &str[0], strlen);
			return (width);
		}
	}
	return (write(1, str, strlen));
}
