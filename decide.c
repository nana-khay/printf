#include "lists.h"

/**
 * decision - Decide which function to use based on specifier
 * @d: The specifier character to determine the function
 *
 * Description: This function takes a specifier character and determines
 *              which function to use based on the specifier
 *
 * Return: A function pointer based on the specifier or NULL.
 */

int (*decision(char d))(va_list)
{
	/*specifiers choose[] = {
		{'s', _string},
		{'c', _char},
		{'d', _decimal},
		{'i', _integer},
		{'\0', NULL}
	};*/

	int i;
	int (*func[])(va_list) = {_string, _char, _decimal, _integer, _uinteger, address, percent, nothing};
	const char specifiers[] = "scdilp%0";

	/*printf("printf %c -- %c\n", choose[1].c, d);
	while (choose[i].c != '\0')
	{
		printf("HH\n");
		if (choose[i].c == d)
			return (choose[i].func);
		i++;
	}
	*/
	for (i = 0; specifiers[i]; i++)
	{
		if (d == specifiers[i])
		{
			return (func[i]);
		}
	}

	return (NULL);
}
