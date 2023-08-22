/*_putchar */
#include "main.h"

/**
 *_putchar - character print function
 *@c: character input
 *
 *Return: number of print
 */

int _putchar(char c)

{
	return (write(1, &c, 1));
}
