#include "main.h"

/**
 * print_special_string - Print an exclusive string with special formatting.
 * @val: Argument.
 * Return: The length of the string.
 */
int print_special_string(va_list val)
{
	char *inputString;
	int i, length = 0;
	int asciiValue;

	inputString = va_arg(val, char *);

	if (inputString == NULL)
		inputString = "(null)";

	for (i = 0; inputString[i] != '\0'; i++)
	{
		if (inputString[i] < 32 || inputString[i] >= 127)
		{
		        _putchar('\\');
		        _putchar('x');
			length += 2;
			asciiValue = inputString[i];

			if (asciiValue < 16)
			{
				_putchar('0');
				length++;
			}

			length += print_HEX_aux(asciiValue);
		}
		else
		{
			_putchar(inputString[i]);
			length++;
		}
	}

	return length;
}

