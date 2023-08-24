#include "main.h"

/**
 *print_revstr - prints a reversed string
 *@ap: argument list
 *@buff: buffer
 *@tags: flags specifier
 *@width: width specifier
 *@precision: precision specifier
 *@size: size specifier
 *
 *Return: print reversed str count
 */

int print_revstr(va_list ap, char buff[], int tags,
	int width, int precision, int size)
{
	int id, poll = 0;
	char *str;

	UNUSED(buff);
	UNUSED(tags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(ap, char *);

	if (str == NULL)
	{
		UNUSED(precision);
		str = "(null)";
	}

	for (id = 0; str[id]; id++)
	;
	for (id = id - 1; id >= 0; id--)
	{
		char rc = str[id];

		write(1, &rc, 1);
		poll++;
	}

	return (poll);
}
