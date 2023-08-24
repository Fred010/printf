#include "main.h"

/**
 *print_check - print hex strings
 *@ap: argument list
 *@buff: buffer
 *@tags: flags specifier
 *@width: width specifier
 *@precision: precision specifier
 *@size: size specifier
 *
 *Return: print formatted char count
 */

int print_check(va_list ap, char buff[], int tags,
	int width, int precision, int size)
{
	int id = 0, balance = 0;
	char *str = va_arg(ap, char *);

	UNUSED(tags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[id] != '\0')
	{
		if (print_brew(str[id]))
			buff[id + balance] = str[id];
		else
			balance += standardize(str[id], buff, id + balance);
		id++;
	}

	buff[id + balance] = '\0';
	return (write(1, buff, id + balance));
}
