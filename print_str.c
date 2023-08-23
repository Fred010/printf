#include "main.h"

/**
 *print_str - function to print a string
 *@roll: list given to function
 *
 *Return: number of printed strings
 */

int print_str(va_list roll)

{
	int print_poll = 0;
	char *str = va_arg(roll, char *);

	if (str == NULL)
		str = "(null)";

	while (str[print_poll] != '\0')
		print_poll += _putchar(str[print_poll]);

	return (print_poll);
}
