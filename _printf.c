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
 * _printf - prints formatted data to stdout
 * @format: string that contains the format to print
 * Return: number of characters written
 */
int _printf(char *format, ...)
{
	int written = 0, (*structype)(char *, va_list);
	char q[3];
	va_list pa;

	if (format == NULL)
		return (-1);
	q[2] = '\0';
	va_start(pa, format);
	_putchar(-1);
	while (format[0])
	{
		if (format[0] == '%')
		{
			structype = driver(format);
			if (structype)
			{
				q[0] = '%';
				q[1] = format[1];
				written += structype(q, pa);
			}
			else if (format[1] != '\0')
			{
				written += _putchar('%');
				written += _putchar(format[1]);
			}
			else
			{
				written += _putchar('%');
				break;
			}
			format += 2;
		}
		else
		{
			written += _putchar(format[0]);
			format++;
		}
	}
	_putchar(-2);
	return (written);
}
