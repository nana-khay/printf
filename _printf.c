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




#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...)
{
    va_list args;  // To handle variable arguments
    int printed_chars = 0;  // To count printed characters

    va_start(args, format);  // Initialize the va_list

    // Iterate through the format string
    while (*format)
    {
        if (*format != '%')
        {
            _putchar(*format);
            printed_chars++;
        }
        else
        {
            // Handle conversion specifier
            format++;  // Move past '%'
            if (*format == 'c')
            {
                char c = va_arg(args, int);  // Fetch a character argument
                _putchar(c);
                printed_chars++;
            }
            else if (*format == 's')
            {
                char *s = va_arg(args, char *);  // Fetch a string argument
                // Print the string (you'll need to implement _puts or similar)
                printed_chars += _puts(s);
            }
            else if (*format == '%')
            {
                _putchar('%');
                printed_chars++;
            }
            // Add handling for more conversion specifiers as needed
        }
        format++;  // Move to the next character in the format string
    }

    va_end(args);  // Clean up the va_list
    return printed_chars;  // Return the total character count
}
