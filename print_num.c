#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_binary - Print an unsigned integer in binary format
 * @args: The va_list containing the unsigned integer
 *
 * Return: The number of characters printed
 */
int print_binary(va_list args)
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
}
