#include "main.h"

/**
 * precision_fetch - deploys the precision parameter
 * @format: formatted string
 * @ap: argument list
 * @index: arguments scope
 *
 * Return: precision flag
 */

int precision_fetch(const char *format, int *index, va_list ap)
{
	int precision = -1;
	int index_c = *index + 1;

	if (format[index_c] != '.')
		return (precision);

	precision = 0;

	for (index_c += 1; format[index_c] != '\0'; index_c++)
	{
		if (num_find(format[index_c]))
		{
			precision *= 10;
			precision += format[index_c] - '0';
		}
		else if (format[index_c] == '*')
		{
			index_c++;
			precision = va_arg(ap, int);
			break;
		}
		else
			break;
	}
	return (precision);
}
