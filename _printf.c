#include "holberton.h"

/**
 * _printf - Print formatted.
 * @format: Variable.
 *
 * Return: Number of characters written.
 */

int _printf(const char *format, ...)
{
	va_list list;
	format_t type[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"i", print_number},
		{"d", print_number},
		{"u", print_u_number},
		{"b", binary},
		{"r", reverse},
		{"o", octal},
		{"x", hex},
		{"X", Hex},
		{NULL, NULL}
	};
	int print;

	if (!format)
		return (-1);

	va_start(list, format);
	print = find_type(format, type, list);
	va_end(list);
	return (print);
}
