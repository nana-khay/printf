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
