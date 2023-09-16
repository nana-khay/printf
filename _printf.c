/*#include "main.h"
#include <stdio.h>
#include <stdarg.h>
*/
/**
 * _printf - Printf function
 * @format: format
 * Return: conversions
 */

/* int _printf(const char *format, ...)
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
*/
#include "lists.h"
/**
 * _printf - Custom printf function implementation
 * @format: The format string containing placeholders
 * @...: Additional arguments for placeholders
 *
 * Description: This function simulates the behavior of the printf function
 *
 * Return: The total count of characters printed.
 */


int _printf(const char *format, ...)
{
        int cnt = 0;
        int i = 0;
        va_list args;

        va_start(args, format);

        while (format[i] != '\0')
        {
                cnt++;
                if (format[i] == '%')
                {
                        if (format[i + 1] == '%')
                        {

                        }
                        if (format[i + 1] != '\0')
                        {
                                int (*function)(va_list) = decision(format[i + 1]);

                                if (function != NULL)
                                {
                                        /*cnt +=*/
                                        function(args);
                                        i++;
                                }
                                else
                                {
                                        _putchar(format[i]);
                                        /*cnt++;*/
                                }
                        }
                }
                else
                {
                        _putchar(format[i]);            }
                i++;
        }

        va_end(args);
        return (cnt);
}
~
