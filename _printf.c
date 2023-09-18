/**#include "main.h"


 * _printf - A function for formatted printing, determining the correct format.
 * @format: The format string to process.
 * Return: The length of the printed output.
 
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
*/




#include "main.h"
/**
 * _printf - is a function that selects the correct function to print.
 * @format: identifier to look for.
 * Return: the length of the string.
 */
int _printf(const char * const format, ...)
{
	convert_match m[] = {
		{"%s", printf_string}, {"%c", printf_char},
		{"%%", printf_37},
		{"%i", printf_int}, {"%d", printf_dec}, {"%r", printf_srev},
		{"%R", printf_rot13}, {"%b", printf_bin}, {"%u", printf_unsigned},
		{"%o", printf_oct}, {"%x", printf_hex}, {"%X", printf_HEX},
		{"%S", printf_exclusive_string}, {"%p", printf_pointer}
	};

	va_list args;
	int i = 0, j, len = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

Here:
	while (format[i] != '\0')
	{
		j = 13;
		while (j >= 0)
		{
			if (m[j].id[0] == format[i] && m[j].id[1] == format[i + 1])
			{
				len += m[j].f(args);
				i = i + 2;
				goto Here;
			}
			j--;
		}
		_putchar(format[i]);
		len++;
		i++;
	}
	va_end(args);
	return (len);
}
