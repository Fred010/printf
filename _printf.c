#include "main.h"

/**
 * buffer_output - outputs buffer if there is any
 * @buff: character array
 * @id_buff: buffer indexes
 */

void buffer_output(char buff[], int *id_buff)
{
	if (*id_buff > 0)
	{
		write(1, &buff[0], *id_buff);
	}
	*id_buff = 0;
}

/**
 * _printf - prints formatted input
 * @format: input string
 *
 * Return: print character count
 */

int _printf(const char *format, ...)
{
	char buff[BUFF_SIZE];
	int  n, mark = 0, char_count = 0;
	int tags, width, precision, size, id_buff = 0;
	va_list ap;

	if (format == NULL)
		return (-1);
	va_start(ap, format);

	for (n = 0; format && format[n] != '\0'; n++)
	{
		if (format[n] != '%')
		{
			buff[id_buff++] = format[n];

			if (id_buff == BUFF_SIZE)
			{
				buffer_output(buff, &id_buff);
			}

			char_count++;
		}
		else
		{
			buffer_output(buff, &id_buff);
			tags = flag_fetch(format, &n);
			width = width_fetch(format, &n, ap);
			precision = precision_fetch(format, &n, ap);
			size = size_fetch(format, &n);
			++n;
			mark = print_ctrl(format, &n, ap, buff, tags, width, precision, size);
			if (mark == -1)
				return (-1);
			char_count += mark;
		}
	}
	buffer_output(buff, &id_buff);
	va_end(ap);
	return (char_count);
}

