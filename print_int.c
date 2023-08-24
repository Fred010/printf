#include "main.h"

/**
 *print_int - prints integers
 *@ap: argument list
 *@buff: buffer
 *@tags: flags specifier
 *@width: width specifier
 *@precision: precision specifier
 *@size: size specifier
 *
 *Return: print integer count
 */

int print_int(va_list ap, char buff[], int tags,
	int width, int precision, int size)
{
	int loc = BUFF_SIZE - 2, neg = 0;
	unsigned int num;
	long int n = va_arg(ap, long int);

	n = _int_conversion(n, size);
	num = (unsigned long int) n;

	if (n == 0)
	{
		buff[loc--] = '0';
	}

	buff[BUFF_SIZE - 1] = '\0';

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		neg = 1;
	}

	while (num > 0)
	{
		buff[loc--] = (num % 10) + '0';
		num /= 10;
	}

	loc++;
	return (_int_print(neg, loc, buff, tags, width, precision, size));
}
