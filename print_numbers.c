#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_integer - Print an integer
 * @args: The va_list containing the integer to be printed
 *
 * Return: The number of characters printed
 */
int print_integer(va_list args)
{
    int num = va_arg(args, int);
    int count = 0;

    count += printf("%d", num); // Print the integer

    return count;
}
