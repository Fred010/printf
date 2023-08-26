#include "main.h"

/**
 * flag_fetch - deploys active tags
 * @format: formatted string
 * @index: placeholder for parameters
 *
 * Return: flags
 */

int flag_fetch(const char *format, int *index)
{
	int n, index_c, tags = 0;
	const char FLAGS_CHAR[] = {'-', '+', '0', '#', ' ', '\0'};
	const char FLAGS_ARRAY[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (index_c = *index + 1; format[index_c] != '\0'; index_c++)
	{
		for (n = 0; FLAGS_CHAR[n] != '\0'; n++)
			if (format[index_c] == FLAGS_CHAR[n])
			{
				tags |= FLAGS_ARRAY[n];
				break;
			}
		if (FLAGS_CHAR[n] == 0)
			break;
	}
	*index = index_c - 1;
	return (tags);
}
