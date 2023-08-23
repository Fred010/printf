#include "main.h"

/**
 * func_fetch - checks for right specifier
 * @format: inputted string
 * @roll: list of arguments
 * @corollary: struct of array specifiers
 *
 * Return: prints number
 */

int func_fetch(const char *format, va_list roll, form_t *corollary)
{
	int print_poll = 0 id1 = 0, id2 = 0;

	while (format[id] != '\0')
	{
		if (format[id1] == '%')
		{
			id1++;

			while (corollary[id2].opr != NULL)
			{
				if (format[id1] == '%')
				{
					print_poll += _putchar('%');
					break;
				}
				else if (*(corollary[id2].opr) == format[id1])
				{
					print_poll += corollary[id2].fn(roll);
					if (print_poll == -1)
						return (-1);
					break;
				}
				id2++;
			}
			if (corollary[id2].opr == NULL)
			{
				print_poll += _putchar('%');
				print_poll += _putchar(format[id1]);
			}
		}
		else
			print_poll += _putchar(format[id1]);
		id1++;
	}
	return (print_poll);
}

/**
 * _printf - prints formatted string to stdout
 * @format: inputted string
 *
 * Return: print number and -1 if error
 */

int _printf(const char *format, ...)
{
	int print_poll = 0;
	va_list roll;

	form_t corollary[] = {
		{"c", print_char},
		{"s", print_str},
		{"d", print_int},
		{"i", print_int},
		{"b", print_bin},
		{"u", print_uni},
		{"o", print_oct},
		{"x", print_hex},
		{"X", print_hex_upper},
		{"S", print_strexe},
		{"p", print_ptr},
		{"r", print_revstr},
		{"R", print_rotstr},
		{NULL, NULL}
	};

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(roll, format);

	print_poll = func_fetch(format, roll, corollary);

	va_end(roll);

	return (print_poll);
}
