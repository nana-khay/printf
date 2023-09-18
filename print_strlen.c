#include "main.h"

/**
 * getStringLength - Calculates the length of a string.
 * @s: A pointer to a character array.
 * Return: The length of the string.
 */
int getStringLength(char *s)
{
    int length;

    for (length = 0; s[length] != 0; length++)
        ;

    return length;
}

/**
 * getStringLengthConst - Calculates the length of a constant string.
 * @s: A constant pointer to a character array.
 * Return: The length of the constant string.
 */
int getStringLengthConst(const char *s)
{
    int length;

    for (length = 0; s[length] != 0; length++)
        ;

    return length;
}
