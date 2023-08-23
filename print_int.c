#include "main.h"

/**
 *print_int - outputs a given number
 *@roll: list inputted
 *
 *Return: number of print integers
 */

int print_int(va_list roll)
{
	int n, fact = 1, print_poll = 0;
	unsigned int mark;

	n = va_arg(roll, int);

	if (n < 0)
	{
		print_poll += _putchar('-');
		n *= -1;
	}

	mark = n;

	while (mark / fact > 9)
		fact *= 10;

	while (fact != 0)
	{
		print_poll += _putchar((mark / fact) + '0');
		mark %= fact;
		fact /= 10;
	}

	return (print_poll);
}
