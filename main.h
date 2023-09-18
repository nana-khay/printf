/**#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>


 * struct convert_match - match the conversion specifiers for custom_printf
 * @id: a string representing the specifier, e.g., "%d", "%s"
 * @f: a function pointer for the conversion specifier
 
typedef struct convert_match
{
    char *id;
    int (*f)(va_list);
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

#endif
*/




#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * struct structprint - structure containing
 * @q: the location and method to translate data to characters.
 * @u: print function for specific type.
 *
 * Return: int
 */
typedef struct structprint
{
	char *q;
	int (*u)(char *format, va_list);
} structype;

int _putchar(char ch);
int _puts(char *string);
int printc(char *format, va_list);
int printstr(char *format, va_list);
int (*driver(char *format))(char *format, va_list);
int _printf(char *format, ...);
int printint(char *format, va_list pa);
int integer(int number);
int contadordigit(int number);
int _abs(int number);
int printpercent(char *format, va_list pa);
int printhex(char *format, va_list);
int printHEX(char *format, va_list);
int printocta(char *format, va_list);
int print_unsign(char *format, va_list);
#endif
