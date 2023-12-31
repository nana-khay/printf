#include "main.h"

/**
 * print_hex - Prints a hexadecimal number.
 * @val: Arguments.
 * Return: The count of printed hexadecimal digits.
 */
int print_hex(va_list val)
{
    int i;
    int *hexDigits;
    int digitCount = 0;
    unsigned int number = va_arg(val, unsigned int);
    unsigned int temp = number;

    while (number / 16 != 0)
    {
        number /= 16;
        digitCount++;
    }
    digitCount++;

    hexDigits = malloc(digitCount * sizeof(int));

    for (i = 0; i < digitCount; i++)
    {
        hexDigits[i] = temp % 16;
        temp /= 16;
    }

    for (i = digitCount - 1; i >= 0; i--)
    {
        if (hexDigits[i] > 9)
            hexDigits[i] = hexDigits[i] + 39;

            _putchar(hexDigits[i] + '0');
    }

    free(hexDigits);
    return digitCount;
}
