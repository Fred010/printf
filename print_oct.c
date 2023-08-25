#include "main.h"

/**
 *print_oct - prints an octal sign of a char
 *@ap: arguments list
 *@buff: buff array to handle print
 *@tags: flag specifier
 *@width: width specifier
 *@precision: precision specifier
 *@size: size specifier
 *Return: number of character printed
 */

int print_oct(va_list ap, char buff[],
	int tags, int width, int precision, int size)
{
	int loc = BUFF_SIZE - 2;
	unsigned long int num = va_arg(ap, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = _uint_conversion(num, size);

	if (num == 0)
		buff[loc--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buff[loc--] = (num % 8) + '0';
		num /= 8;
	}

	if (tags & F_HASH && init_num != 0)
		buff[loc--] = '0';

	loc++;

	return (uint_log(0, loc, buff, tags, width, precision, size));
}
