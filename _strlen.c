#include "main.h"

/**
 *_strlen - get the string length
 *@str: given string
 *Return: string length
 */
int _strlen(char *str)
{
	int id;

	for (id = 0; str[id] != '\0'; id++)
	;

	return (id);
}
