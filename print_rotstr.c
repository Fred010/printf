#include "main.h"

/**
 *print_rotstr - prints a rotated string
 *@ap: argument list
 *@buff: buffer
 *@tags: flags specifier
 *@width: width specifier
 *@precision: precision specifier
 *@size: size specifier
 *
 *Return: print rotated str count
 */

int print_rotstr(va_list ap, char buff[], int tags,
	int width, int precision, int size)
{
	int poll = 0;
	char rs, *str;
	unsigned int r1, r2;
	char start[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char end[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(ap, char *);

	UNUSED(buff);
	UNUSED(tags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(YEAH)";
	for (r1 = 0; str[r1]; r1++)
	{
		for (r2 = 0; start[r2]; r2++)
		{
			if (start[r2] == str[r1])
			{
				rs = end[r2];
				write(1, &rs, 1);
				poll++;
				break;
			}
		}

		if (!start[r2])
		{
			rs = str[r1];
			write(1, &rs, 1);
			poll++;
		}
	}

	return (poll);
}
