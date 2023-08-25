#include "main.h"

/**
 *print_uint - prints an unsigned number
 *@ap: arguments list
 *@buff: buff array
 *@tags: flag specifier
 *@width: width specifier
 *@precision: precision specifier
 *@size: size specifier
 *Return: character print
 */

int print_uint(va_list ap, char buff[],
	int tags, int width, int precision, int size)
{
	int loc = BUFF_SIZE - 2;
	unsigned long int num = va_arg(ap, unsigned long int);

	num = _uint_conversion(num, size);

	if (num == 0)
		buff[loc--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buff[loc--] = (num % 10) + '0';
		num /= 10;
	}

	loc++;

	return (uint_log(0, loc, buff, tags, width, precision, size));
}
