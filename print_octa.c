#include "main.h"

/**
 * print_octal - Prints an octal number.
 * @val: Arguments.
 * Return: The count of printed octal digits.
 */
int print_octal(va_list val)
{
    int i;
    int *octalDigits;
    int digitCount = 0;
    unsigned int number = va_arg(val, unsigned int);
    unsigned int temp = number;

    while (number / 8 != 0)
    {
        number /= 8;
        digitCount++;
    }
    digitCount++;

    octalDigits = malloc(digitCount * sizeof(int));

    for (i = 0; i < digitCount; i++)
    {
        octalDigits[i] = temp % 8;
        temp /= 8;
    }

    for (i = digitCount - 1; i >= 0; i--)
    {
        _putchar(octalDigits[i] + '0');
    }

    free(octalDigits);
    return digitCount;
}
