#include "main.h"
/**
 * print_ctrl - prints specified type of char
 * @form: formatted string
 * @ap: arguments list
 * @index: index
 * @buff: buffer array
 * @tags: flag specifier
 * @width: width specifier
 * @precision: precision specifier
 * @size: size specifier
 * Return: 1 or 2;
 */
int print_ctrl(const char *form, int *index, va_list ap, char buff[],
	int tags, int width, int precision, int size)
{
	int loc, ulen = 0, char_print = -1;
	form_t form_types[] = {
		{'c', print_char}, {'s', print_str}, {'%', print_percent},
		{'loc', print_int}, {'d', print_int}, {'b', print_bin},
		{'u', print_uint}, {'o', print_oct}, {'x', print_hex},
		{'X', print_uhex_upper}, {'p', print_ptr}, {'S', print_check},
		{'r', print_revstr}, {'R', print_rotstr}, {'\0', NULL}
	};
	for (loc = 0; form_types[loc].form != '\0'; loc++)
		if (form[*index] == form_types[loc].form)
			return (form_types[loc].func(ap, buff, tags, width, precision, size));

	if (form_types[loc].form == '\0')
	{
		if (form[*index] == '\0')
			return (-1);
		ulen += write(1, "%%", 1);
		if (form[*index - 1] == ' ')
			ulen += write(1, " ", 1);
		else if (width)
		{
			--(*index);
			while (form[*index] != ' ' && form[*index] != '%')
				--(*index);
			if (form[*index] == ' ')
				--(*index);
			return (1);
		}
		ulen += write(1, &form[*index], 1);
		return (ulen);
	}
	return (char_print);
}
