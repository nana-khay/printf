#include "main.h"

/**
 * print_unsigned - Prints an unsigned integer.
 * @args: Argument to print.
 * Return: The number of characters printed.
 */
int print_unsigned(va_list args)
{
    unsigned int number = va_arg(args, unsigned int);
    int lastDigit = number % 10, digit, exponent = 1;
    int charCount = 1;
    int temp = number;

    number = number / 10;

    if (lastDigit < 0)
    {
        _putchar('-');
        temp = -temp;
        number = -number;
        lastDigit = -lastDigit;
        charCount++;
    }

    if (number > 0)
    {
        while (number / 10 != 0)
        {
            exponent = exponent * 10;
            number = number / 10;
        }

        number = temp;

        while (exponent > 0)
        {
            digit = number / exponent;
            _putchar(digit + '0');
            number = number - (digit * exponent);
            exponent = exponent / 10;
            charCount++;
        }
    }

    _putchar(lastDigit + '0');
    return charCount;
}
