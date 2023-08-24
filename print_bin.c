#include "main.h"

/**
 *print_bin - prints a string
 *@ap: argument list
 *@buff: buffer
 *@tags: flags specifier
 *@width: width specifier
 *@precision: precision specifier
 *@size: size specifier
 *
 *Return: print bin count
 */

int print_bin(va_list ap, char buff[], int tags,
	int width, int precision, int size)
{
	int poll;
	unsigned int b1, b2, b3, bsum, bb[32];

	UNUSED(buff);
	UNUSED(tags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	b1 = va_arg(ap, unsigned int);
	b2 = 2147483648;
	bb[0] = b1 / b2;

	for (b3 = 1; b3 < 32; b3++)
	{
		b2 /= 2;
		bb[b3] = (b1 / b2) % 2;
	}

	for (b3 = 0, bsum = 0, poll = 0; b3 < 32; b3++)
	{
		bsum += bb[b3];
		if (bsum || b3 == 31)
		{
			char bc = '0' + bb[b3];

			write(1, &bc, 1);
			poll++;
		}
	}

	return (poll);
}
