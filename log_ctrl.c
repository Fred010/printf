#include "main.h"

/**
 *char_write_ctrl - Prints a string
 *@c: char types.
 *@buff: buff array to handle print
 *@tags:  Calculates active tags.
 *@width: get width.
 *@precision: precision specifier
 *@size: Size specifier
 *
 *Return: Number of chars printed.
 */

int char_write_ctrl(char c, char buff[],
	int tags, int width, int precision, int size)
{
	int n = 0;
	char pad = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (tags & F_ZERO)
		pad = '0';

	buff[n++] = c;
	buff[n] = '\0';

	if (width > 1)
	{
		buff[BUFF_SIZE - 1] = '\0';
		for (n = 0; n < width - 1; n++)
			buff[BUFF_SIZE - n - 2] = pad;

		if (tags & F_MINUS)
			return (write(1, &buff[0], 1) +
				write(1, &buff[BUFF_SIZE - n - 1], width - 1));
		else
			return (write(1, &buff[BUFF_SIZE - n - 1], width - 1) +
				write(1, &buff[0], 1));
	}

	return (write(1, &buff[0], 1));
}

/**
 *_int_print - Prints a string
 *@neg: Lista of arguments
 *@index: char types.
 *@buff: buff array to handle print
 *@tags:  Calculates active tags
 *@width: get width.
 *@precision: precision specifier
 *@size: Size specifier
 *
 *Return: Number of chars printed.
 */

int _int_print(int neg, int index, char buff[],
	int tags, int width, int precision, int size)
{
	int len = BUFF_SIZE - index - 1;
	char pad = ' ', more_char = 0;

	UNUSED(size);

	if ((tags & F_ZERO) && !(tags & F_MINUS))
		pad = '0';
	if (neg)
		more_char = '-';
	else if (tags & F_PLUS)
		more_char = '+';
	else if (tags & F_SPACE)
		more_char = ' ';

	return (num_print(index, buff, tags, width, precision,
		len, pad, more_char));
}

/**
 *num_print - Write a number using a bufffer
 *@index: Index at which the number starts on the buff
 *@buff: buff
 *@tags: tags
 *@w: width
 *@p: Precision specifier
 *@len: Number len
 *@pad: Pading char
 *@more_char: Extra char
 *
 *Return: Number of printed chars.
 */
int num_print(int index, char buff[], int tags, int w,
		int p, int len, char pad, char more_char)
{
	int n, pad_start = 1;

	if (p == 0 && index == BUFF_SIZE - 2 && buff[index] == '0' && w == 0)
		return (0);
	if (p == 0 && index == BUFF_SIZE - 2 && buff[index] == '0')
		buff[index] = pad = ' ';
	if (p > 0 && p < len)
		pad = ' ';
	while (p > len)
		buff[--index] = '0', len++;
	if (more_char != 0)
		len++;
	if (w > len)
	{
		for (n = 1; n < w - len + 1; n++)
			buff[n] = pad;
		buff[n] = '\0';
		if (tags & F_MINUS && pad == ' ')
		{
			if (more_char)
				buff[--index] = more_char;
			return (write(1, &buff[index], len) + write(1, &buff[1], n - 1));
		}
		else if (!(tags & F_MINUS) && pad == ' ')
		{
			if (more_char)
				buff[--index] = more_char;
			return (write(1, &buff[1], n - 1) + write(1, &buff[index], len));
		}
		else if (!(tags & F_MINUS) && pad == '0')
		{
			if (more_char)
				buff[--pad_start] = more_char;
			return (write(1, &buff[pad_start], n - pad_start) +
				write(1, &buff[index], len - (1 - pad_start)));
		}
	}
	if (more_char)
		buff[--index] = more_char;
	return (write(1, &buff[index], len));
}

/**
 *uint_log - Writes an unsigned number
 *@neg: Number indicating if the num is negative
 *@index: Index at which the number starts in the buff
 *@buff: Array of chars
 *@tags: tags specifiers
 *@width: Width specifier
 *@precision: Precision specifier
 *@size: Size specifier
 *
 *Return: Number of written chars.
 */
int uint_log(int neg, int index,
	char buff[],
	int tags, int width, int precision, int size)
{
	int len = BUFF_SIZE - index - 1, n = 0;
	char pad = ' ';

	UNUSED(neg);
	UNUSED(size);

	if (precision == 0 && index == BUFF_SIZE - 2 && buff[index] == '0')
		return (0);

	if (precision > 0 && precision < len)
		pad = ' ';

	while (precision > len)
	{
		buff[--index] = '0';
		len++;
	}

	if ((tags & F_ZERO) && !(tags & F_MINUS))
		pad = '0';

	if (width > len)
	{
		for (n = 0; n < width - len; n++)
			buff[n] = pad;

		buff[n] = '\0';

		if (tags & F_MINUS)
		{
			return (write(1, &buff[index], len) + write(1, &buff[0], n));
		}
		else
		{
			return (write(1, &buff[0], n) + write(1, &buff[index], len));
		}
	}

	return (write(1, &buff[index], len));
}

/**
 *ptr_log - Write a memory address
 *@buff: Arrays of chars
 *@index: Index at which the number starts in the buff
 *@len: len of number
 *@width: Width specifier
 *@tags: tags specifier
 *@pad: Char representing the padding
 *@more_char: Char representing extra char
 *@pad_start: Index at which padding should start
 *
 *Return: Number of written chars.
 */
int ptr_log(char buff[], int index, int len,
	int width, int tags, char pad, char more_char, int pad_start)
{
	int n;

	if (width > len)
	{
		for (n = 3; n < width - len + 3; n++)
			buff[n] = pad;
		buff[n] = '\0';
		if (tags & F_MINUS && pad == ' ')
		{
			buff[--index] = 'x';
			buff[--index] = '0';
			if (more_char)
				buff[--index] = more_char;
			return (write(1, &buff[index], len) + write(1, &buff[3], n - 3));
		}
		else if (!(tags & F_MINUS) && pad == ' ')
		{
			buff[--index] = 'x';
			buff[--index] = '0';
			if (more_char)
				buff[--index] = more_char;
			return (write(1, &buff[3], n - 3) + write(1, &buff[index], len));
		}
		else if (!(tags & F_MINUS) && pad == '0')
		{
			if (more_char)
				buff[--pad_start] = more_char;
			buff[1] = '0';
			buff[2] = 'x';
			return (write(1, &buff[pad_start], n - pad_start) +
				write(1, &buff[index], len - (1 - pad_start) - 2));
		}
	}

	buff[--index] = 'x';
	buff[--index] = '0';
	if (more_char)
		buff[--index] = more_char;
	return (write(1, &buff[index], BUFF_SIZE - index - 1));
}
