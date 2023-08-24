#include "main.h"

/**
 * width_fetch - deploys width parameter on arguments
 * @format: formatted string
 * @index: arguments parameter
 * @ap: argument list
 *
 * Return: prints width of argument
 */

int width_fetch(const char *format, int *index, va_list ap)
{
	int index_c, width = 0;

	for (index_c = *index + 1; format[index_c] != '\0'; index_c++)
	{
		if (num_find(format[index_c]))
		{
			width *= 10;
			width += format[index_c] - '0';
		}
		else if (format[index_c] == '*')
		{
			index_c++;
			width = va_arg(ap, int);
			break;
		}
		else
			break;
	}
	*index = index_c - 1;
	return (width);
}
