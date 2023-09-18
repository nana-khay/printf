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

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
