#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Printf function
 * @format: format
 * Return: conversions
 */

 int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    char c;
    char *str;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++; 

            switch (*format)
            {
                case 'c':
                    c = va_arg(args, int);
                    putchar(c);
                    count++;
                    break;
                case 's':
                    str = va_arg(args, char *);
                    if (str == NULL)
                        str = "(null)";
                    while (*str)
                    {
                        putchar(*str);
                        str++;
                        count++;
                    }
                    break;
		case 'd':
                case 'i':
                    count += print_integer(args);
                    break;
                case '%':
                    putchar('%');
                    count++;
                    break;
		case 'b':
                    count += print_binary(args);
                    break;
                default:
                    putchar('%');
                    putchar(*format);
                    count += 2;
                    break;
            }
        }
        else
        {
            putchar(*format);
            count++;
        }
        format++;
    }

    va_end(args);
    return count;
}

