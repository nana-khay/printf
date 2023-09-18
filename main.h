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

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>



/**
 * struct format - match the conversion specifiers for printf
 * @id: type char pointer of the specifier i.e (l, h) for (d, i, u, o, x, X)
 * @f: type pointer to function for the conversion specifier
 *
 */

typedef struct format
{
	char *id;
	int (*f)();
} convert_match;

int printf_pointer(va_list val);
int printf_hex_aux(unsigned long int num);
int printf_HEX_aux(unsigned int num);
int printf_exclusive_string(va_list val);
int printf_HEX(va_list val);
int printf_hex(va_list val);
int printf_oct(va_list val);
int printf_unsigned(va_list args);
int printf_bin(va_list val);
int printf_srev(va_list args);
int printf_rot13(va_list args);
int printf_int(va_list args);
int printf_dec(va_list args);
int _strlen(char *s);
int *_strcpy(char *dest, char *src);
int _strlenc(const char *s);
int rev_string(char *s);
int _strlenc(const char *s);
int printf_37(void);
int printf_char(va_list val);
int printf_string(va_list val);
int _putchar(char c);
int _printf(const char *format, ...);

#endif
