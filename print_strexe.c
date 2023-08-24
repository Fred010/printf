#include "main.h"

/**
 * print_strexe - converts and outputs string
 * @roll: list
 *
 * Return: print number
 */

int print_strexe(va_list roll)
{
	char *str;
	int print_poll, id;

	print_poll = 0;
	str = va_arg(roll, char*);

	if (str == NULL)
		str = "(null)";

	for (id = 0; str[id] != '\0'; id++)
	{
		if (str[id] < 32 || str[id] >= 127)
		{
			_putchar('\\');
			_putchar('x');

			if (str[id] < 16)
			{
				_putchar('0');
				print_poll++;
			}
			print_poll += print_int(str[id]);
		}
		else
		{
			_putchar(str[id]);
			print_poll++;
		}
	}
	return (print_poll);
}
