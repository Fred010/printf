#include "main.h"

/**
 * print_brew - checks if char can be printed
 * @c: char to be checked
 *
 * Return: 1 if printable, 0 if otherwise
 */

int print_brew(char c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}

/**
 * standardize - add hex_ascii to buffer
 * @buff: array of char
 * @cipher: ascii key
 * @index: index for addition of ascii key
 *
 * Return: int
 */

int standardize(char cipher, char buff[], int index)
{
	char link[] = "0123456789ABCDEF";

	if (cipher < 0)
		cipher *= -1;

	buff[index++] = '\\';
	buff[index++] = 'x';
	buff[index++] = link[cipher / 16];
	buff[index] = link[cipher % 16];

	return (3);
}

/**
 * num_find - checks if a char is an integer
 * @c: char tobe checked
 *
 * Return: 1 if printable, 0 if otherwise
 */

int num_find(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/**
 * _int_conversion - change a number to a specified type
 * @num: number to be changed
 * @size: array size
 *
 * Return: int
 */

long int _int_conversion(long int num, int size)
{
	if (size == S_SHORT)
		return ((unsigned short)num);
	else if (size == S_LONG)
		return (num);

	return ((int)num);
}

/**
 * _uint_conversion - change a number to a specified type
 * @num: number to be changed
 * @size: array size
 *
 * Return: int
 */

long int _uint_conversion(unsigned long int num, int size)
{
	if (size == S_SHORT)
		return ((unsigned short)num);
	else if (size == S_LONG)
		return (num);

	return ((unsigned int)num);
}
