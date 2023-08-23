#include "main.h"

/**
 *print_hex - converts integers to base 16
 *@roll: list to be converted
 *Return: number of prints
 */

int print_hex(va_list roll)
{
	int *arr, print_poll, id;
	unsigned int n, a;

	n = va_arg(roll, int);
	a = n;
	print_poll = 0;

	while (a / 16)
	{
		print_poll++;
		a /= 16;
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
		arr[id] = n % 16;
		n /= 16;
	}

	for (id = print_poll - 1; id >= 0; id--)
	{
		if (arr[id] <= 9)
			_putchar(arr[id] + '0');
		else
			_putchar((arr[id] % 10) + 'a');
	}

	free(arr);
	return (print_poll);
}
