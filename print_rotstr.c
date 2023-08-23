#include "main.h"

/**
 *print_rotstr - outputs string using the rot 13 method
 *@roll: list
 *
 *Return: number of prints
 */

int print_rotstr(va_list roll)
{
	char *str;
	int print_poll, id;

	str = va_arg(roll, char *);
	print_poll = 0;

	if (str == NULL)
	{
		str = "(null)";
		for (id = 0; str[id] != '\0'; id++)
			print_poll += _putchar(str[id]);
	}
	else
	{
		for (id = 0; str[id] != '\0'; id++)
		{
			if (str[id] >= 'a' && str[id] <= 'z')
			{
				if (str[id] <= 'm')
					print_poll += _putchar(str[id] + 13);
				else
					print_poll += _putchar(str[id] - 13);
			}
			else if (str[id] >= 'A' && str[id] <= 'Z')
			{
				if (str[id] <= 'M')
					print_poll += _putchar(str[id] + 13);
				else
					print_poll += _putchar(str[id] - 13);
			}
			else
			{
				print_poll += _putchar(str[id]);
			}
		}
	}

	return (print_poll);
}
