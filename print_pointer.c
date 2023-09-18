#include "main.h"

/**
 * print_pointer - Prints a hexadecimal representation of a pointer.
 * @val: Arguments.
 * Return: The count of printed characters.
 */
int print_pointer(va_list val)
{
    void *pointer;
    char *nilMessage = "(nil)";
    long int hexValue;
    int digitCount;
    int i;

    pointer = va_arg(val, void*);

    if (pointer == NULL)
    {
        for (i = 0; nilMessage[i] != '\0'; i++)
        {
            _putchar(nilMessage[i]);
        }
        return i;
    }

    hexValue = (unsigned long int)pointer;
    _putchar('0');
    _putchar('x');
    digitCount = print_hex_aux(hexValue);
    return digitCount + 2;
}
