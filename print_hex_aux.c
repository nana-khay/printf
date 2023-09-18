#include "main.h"

/**
 * print_hex_aux - Prints a hexadecimal number.
 * @num: Argument.
 * Return: The count of printed hexadecimal digits.
 */
int print_hex_aux(unsigned long int num)
{
    long int i;
    long int *hexDigits;
    long int digitCount = 0;
    unsigned long int temp = num;

    while (num / 16 != 0)
    {
        num /= 16;
        digitCount++;
    }
    digitCount++;

    hexDigits = malloc(digitCount * sizeof(long int));

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
