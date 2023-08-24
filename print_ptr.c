#include "main.h"

/**
 * print_ptr - outputs address of input
 * @roll: list
 *
 * Return: print number
 */

int print_ptr(va_list roll)
{
	void *ptr;
	char *str;
	int print_poll, id, mark;

	print_poll = 0;
	str = "(empty)";
	ptr = va_arg(roll, void*);

	if (ptr == NULL)
	{
		for (id = 0; str[id] != '\0'; id++)
			_putchar(str[id]);
		return (id);
	}
	mark = (int)ptr;

	print_poll += _putchar('0');
	print_poll += _putchar('x');
	print_poll += print_int(mark);

	return (print_poll);
}
