#include "main.h"

/**
 * print_binary - Prints a binary number.
 * @val: Arguments.
 * Return: The count of printed characters.
 */
int print_binary(va_list val)
{
	int flag = 0;
	int charCount = 0;
	int i, bit = 1, binaryDigit;
	unsigned int num = va_arg(val, unsigned int);
	unsigned int bitmask;

	for (i = 0; i < 32; i++)
	{
		bitmask = ((bit << (31 - i)) & num);
		if (bitmask >> (31 - i))
			flag = 1;
		if (flag)
		{
			binaryDigit = bitmask >> (31 - i);
		        _putchar(binaryDigit + '0');
			charCount++;
		}
	}
	if (charCount == 0)
	{
		charCount++;
		_putchar('0');
	}
	return charCount;
}
