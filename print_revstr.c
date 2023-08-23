#include "main.h"

/**
 * print_revstr - outputs reversed string
 * @roll: list
 *
 * Return: print number
 */

int print_revstr(va_list roll)
{
	char *str;
	int id, print_poll, str_len;

	str = va_arg(roll, char *);
	print_poll = 0;

	if (str == NULL)
		str = "(null)";

	for (str_len = 0; str[str_len] != '\0'; str_len++)

		for (id = str_len - 1; str[id] != '\0'; id--)
			print_poll += _putchar(str[id]);

	return (print_poll);
}
