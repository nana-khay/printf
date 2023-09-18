#include "main.h"

/**
 * print_string - Print a string.
 * @val: Argument.
 * Return: The length of the string.
 */
int print_string(va_list val)
{
    char *inputString;
    int i, length;

    inputString = va_arg(val, char *);

    if (inputString == NULL)
    {
        inputString = "(null)";
        length = getStringLength(inputString);

        for (i = 0; i < length; i++)
        {
            _putchar(inputString[i]);
        }

        return length;
    }
    else
    {
        length = getStringLength(inputString);

        for (i = 0; i < length; i++)
        {
            _putchar(inputString[i]);
        }

        return length;
    }
}
