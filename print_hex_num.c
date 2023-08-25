#include "main.h"

/**
 *print_hex_num - prints lower or upper hex char
 *@ap: arguments list
 *@link: array of values to map the number to
 *@buff: buff array to handle print
 *@tags:  flag specifier
 *@ch_tag: finds active flag
 *@width: width specifier
 *@precision: Precision specifier
 *@size: Size specifier
 *Return: Number of chars printed
 */

int print_hex_num(va_list ap, char link[], char buff[],
	int tags, char ch_tag, int width, int precision, int size)
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
		buff[loc--] = link[num % 16];
		num /= 16;
	}

	if (tags & F_HASH && init_num != 0)
	{
		buff[loc--] = ch_tag;
		buff[loc--] = '0';
	}

	loc++;

	return (uint_log(0, loc, buff, tags, width, precision, size));
}
