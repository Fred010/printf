#include "main.h"

/**
 * size_fetch - deploys the size parameter on arguments
 * @format: formatted string
 * @index: arguments index
 *
 * Return: size of argument
 */

int size_fetch(const char *format, int *index)
{
	int size = 0;
	int index_c = *index + 1;

	if (format[index_c] == 'h')
		size = S_SHORT;
	else if (format[index_c] == 'l')
		size = S_LONG;

	if (size == 0)
	{
		*index = index_c - 1;
	}
	else
	{
		*index = index_c;
	}
	return (size);
}
