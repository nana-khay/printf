#include "main.h"

/**
 * print_HEX_aux - Prints a hexadecimal number.
 * @num: The number to print.
 * Return: The count of characters printed.
 */
int print_HEX_aux(unsigned int num)
{
    int i;
    int *hexDigitsArray;
    int charCount = 0;
    unsigned int temp = num;

    while (num / 16 != 0)
    {
        num /= 16;
        charCount++;
    }
    charCount++;

    hexDigitsArray = malloc(charCount * sizeof(int));

    for (i = 0; i < charCount; i++)
    {
        hexDigitsArray[i] = temp % 16;
        temp /= 16;
    }

    for (i = charCount - 1; i >= 0; i--)
    {
        if (hexDigitsArray[i] > 9)
            hexDigitsArray[i] = hexDigitsArray[i] + 7;
          _putchar(hexDigitsArray[i] + '0');
    }

    free(hexDigitsArray);

    return charCount;
}
