#include <stddef.h>
#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
/**
 * printIdentifiers - prints special characters
 * @next: character after the %
 * @arg: argument for the indentifier
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 */
int printIdentifiers(char next, va_list arg)
{
	int functsIndex = 0;

	identifierStruct functs[] = {
		{"c", print_char},
		{"s", print_str},
		{"d", print_int},
		{"i", print_int},
		{"u", print_unsigned},
		{"b", print_unsignedToBinary},
		{"o", print_oct},
		{"x", print_hex},
		{"X", print_HEX},
		{"S", print_STR},
		{NULL, NULL}
	};

	for (functsIndex = 0; functs[functsIndex].indentifier != NULL; functsIndex++)
	{
		if (functs[functsIndex].indentifier[0] == next)
			return (functs[functsIndex].printer(arg));
	}
	return (0);
}
/**
 * _printf - mimic printf from stdio
 * Description: produces output according to a format
 * write output to stdout, the standard output stream
 * @format: character string composed of zero or more directives
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 * return -1 for incomplete identifier error
 */

int _printf(const char *format, ...)
{
	unsigned int i;
	int idPr = 0, cPr = 0;
	va_list arg;

	va_start(arg, format);
	if (format == NULL)
		return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			cPr++;
			continue;
		}
		if (format[i + 1] == '%')
		{
			_putchar('%');
			cPr++;
			i++;
			continue;
		}
		if (format[i + 1] == '\0')
			return (-1);

		idPr = printIdentifiers(format[i + 1], arg);
		if (idPr == -1 || identifierPrinted != 0)
			i++;
		if (idPr > 0)
			cPr += idPr;

		if (idPr == 0)
		{
			_putchar('%');
			cPr++;
		}
	}
	va_end(arg);
	return (cPr);
}
