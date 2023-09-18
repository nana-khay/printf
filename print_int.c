#include "main.h"

/**
 * print_integer - Prints an integer.
 * @args: Argument to print.
 * Return: The number of characters printed.
 */
int print_integer(va_list args)
{
    int number = va_arg(args, int);
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

/**
 * print_decimal - Prints a decimal number.
 * @args: Argument to print.
 * Return: The number of characters printed.
 */
int print_decimal(va_list args)
{
    int number = va_arg(args, int);
    int lastDigit = number % 10, digit;
    int charCount = 1;
    int exponent = 1;
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
