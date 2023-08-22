#include "main.h"

/**
 *print_char - function to print character
 *@roll: list given to function
 *
 *Return: number of printed character
 */

int print_char(va_list roll)

{
	return (_putchar(va_arg(roll, int)));
}
