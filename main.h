#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

/**
 * struct convert_match - match the conversion specifiers for custom_printf
 * @id: a string representing the specifier, e.g., "%d", "%s"
 * @f: a function pointer for the conversion specifier
 */

typedef struct convert_match
{
    char *id;
    int (*f)(va_list, char[], int, int, int, int);
} convert_match;

int print_pointer(va_list val);
int print_hex_aux(unsigned long int num);
int print_HEX_aux(unsigned int num);
int print_special_string(va_list val);
int print_HEX(va_list val);
int print_hex(va_list val);
int print_octal(va_list val);
int print_unsigned(va_list args);
int print_binary(va_list val);
int print_reverse_string(va_list args);
int print_rot13_string(va_list args);
int print_integer(va_list args);
int print_decimal(va_list args);
int getStringLength(char *s);
int getStringLengthConst(const char *s);
int reverse_string(char *s);
int print_percent(void);
int print_char(va_list val);
int print_string(va_list val);
int _putchar(char ch);
int _printf(const char *format, ...);

#endif /* MAIN_H */
