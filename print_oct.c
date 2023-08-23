#include "main.h"

/**
 *print_oct - converts integers to base 8
 *@roll: list of numbers
 *
 *Return: number of prints
 */

int print_oct(va_list roll)
{
	int *arr;
	int print_poll, id;
	unsigned int n, a;

	n = va_arg(list, int);
	a = n;
	print_poll = 0;

	while (a / 8)
	{
		print_poll++;
		a /= 8;
	}

	print_poll++;

	arr = (int *) malloc(sizeof(int) * print_poll);
	if (arr == NULL)
	{
		free(arr);
		return (0);
	}

	for (id = 0; id < print_poll; id++)
	{
		arr[id] = n % 8;
		n /= 8;
	}

	for (id = print_poll - 1; id >= 0; id--)
	{
		_putchar(arr[id] + '0');
	}

	free(arr);
	return (print_poll);
}
