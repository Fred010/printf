#include "main.h"

/**
 *print_uni - prints unsigned integers
 *@roll: given list
 *
 *Return: number of print integers
 */

int print_uni(va_list roll)
{
	unsigned int n;
	int fact = 1, print_poll = 0;

	n = va_arg(roll, int);

	while (n / fact > 9)
		fact *= 10;

	while (fact != 0)
	{
		print_poll += _putchar((n / fact) + '0');
		n %= fact;
		fact /= 10;
	}

	return (print_poll);
}
