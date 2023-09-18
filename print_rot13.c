#include "main.h"

/**
 * print_rot13_string - Prints a ROT13 encoded string.
 * @args: Argument containing the string to encode.
 * Return: The count of printed characters.
 */
int print_rot13_string(va_list args)
{
    int i, j, counter = 0;
    int foundMatch = 0;
    char *inputString = va_arg(args, char*);
    char alpha[] = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    char beta[] = {"nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM"};

    if (inputString == NULL)
        inputString = "(null)";

    for (i = 0; inputString[i]; i++)
    {
        foundMatch = 0;

        for (j = 0; alpha[j] && !foundMatch; j++)
        {
            if (inputString[i] == alpha[j])
            {
                _putchar(beta[j]);
                counter++;
                foundMatch = 1;
            }
        }

        if (!foundMatch)
        {
            _putchar(inputString[i]);
            counter++;
        }
    }

    return counter;
}
