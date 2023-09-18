#include "main.h"

/**
 * print_reverse_string - Prints a string in reverse order.
 * @args: Argument containing the string to print in reverse.
 * Return: The length of the string.
 */
int print_reverse_string(va_list args)
{
    char *inputString = va_arg(args, char*);
    int i;
    int length = 0;

    if (inputString == NULL)
        inputString = "(null)";

    while (inputString[length] != '\0')
        length++;

    for (i = length - 1; i >= 0; i--)
    {
        _putchar(inputString[i]);
    }

    return length;
}
