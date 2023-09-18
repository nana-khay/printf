#include "main.h"

/**
 * print_char - Prints a character.
 * @val: Arguments.
 * Return: The count of printed characters, which is always 1.
 */
int print_char(va_list val)
{
	char character;

	character = va_arg(val, int);
	_putchar(character);
	return 1;
}
