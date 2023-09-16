/*#include "main.h"
#include <stdio.h>
#include <stdarg.h>
*/
/**
 * print_binary - Print an unsigned integer in binary format
 * @args: The va_list containing the unsigned integer
 *
 * Return: The number of characters printed
 */
/*int print_binary(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int count = 0;
    int binary[32]; // Assuming a 32-bit integer for simplicity
    int i;

    if (num == 0)
    {
        putchar('0');
        return 1;
    }

    for (i = 0; num > 0; i++)
    {
        binary[i] = num % 2;
        num /= 2;
    }

    for (i = i - 1; i >= 0; i--)
    {
        putchar(binary[i] + '0');
        count++;
    }

    return count;
}*/

#include "lists.h"
#include <limits.h>
#include <stdlib.h>
/**
 * _putdec - Print an integer to standard output
 * @x: The integer to be printed
 * @count: The count of characters printed so far
 * Return: The updated count of characters printed.
 */

int _putdec(int x, int count)
{
        int d = x;

        if (x < 0)
        {
                d = -x;
                count +=_putchar('-');
                count = count + 1;
        }

        if (d / 10)
        {
                count = _putdec(d / 10, count);
        }

        count += _putchar(d % 10 + '0');
        return (count + 1);

}
/**
 * _string - Print a string to standard output
 * @args: The va_list containing the string to be printed
 * Return: The count of characters printed.
 */

int _string(va_list args)
{
        int count;

        count = 0;
        char *str = va_arg(args, char*);

        while (*str)
        {
                count = _putchar(*str);
                str++;
        }
        return (count);

}
/**
 * _char - Print a character to standard output
 * @args: The va_list containing the character to be printed
 * Return: Always 1
 */

int _char(va_list args)
{
        char ch = va_arg(args, int);

        if (ch == '%')
                return (1);
        return (_putchar(ch));
}
/**
 * _decimal - Print an integer as a decimal to standard output
 * @args: The va_list containing the integer to be printed
 * Return: The count of characters printed.
 */

int _decimal(va_list args)
{
        int count = 0;

        int dec = va_arg(args, int);

        count = _putdec(dec, 0);

        return (count);
}

/**
 * _integer - Print an integer to standard output
 * @args: The va_list containing the integer to be printed
 *
 * Description: This function takes an integer from the va_list and uses the
 *              _putdec function to print it to the standard output.
 *
 * Return: The count of characters printed.
 */

int _integer(va_list args)
{
        int x = va_arg(args, int);

        return (_putdec(x, 0));
}
int nothing(va_list args)
{
        return (0);
}

int percent(va_list args)
{
        _putchar('%');
}
int address(va_list args)
{

        return (0);
}

