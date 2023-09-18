#include "main.h"


/**
 * _printf - A function for formatted printing, determining the correct format.
 * @format: The format string to process.
 * Return: The length of the printed output.
 */

int _printf(const char * const format, ...)
{

	convert_match format_specifiers[] = {
		{"%s", print_string}, {"%c", print_char},
		{"%%", print_percent},
		{"%i", print_integer}, {"%d", print_decimal}, {"%r", print_reverse_string},
		{"%R", print_rot13_string}, {"%b", print_binary}, {"%u", print_unsigned},
		{"%o", print_octal}, {"%x", print_hex}, {"%X", print_HEX},
		{"%S", print_special_string}, {"%p", print_pointer}
	};

	va_list args;
	int i = 0, j, length = 0;

	va_start(args, format);

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	while (format[i] != '\0')
	{
		j = 13;
		while (j >= 0)
		{
			if (format_specifiers[j].id[0] == format[i] && format_specifiers[j].id[1] == format[i + 1])
			{
				length += format_specifiers[j].f(args);
				i = i + 2;
				goto Continue;
			}
			j--;
		}

		_putchar(format[i]);
		length++;
		i++;
Continue:
		continue;
	}
	va_end(args);
	return (length);
}

