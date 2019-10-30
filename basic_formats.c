#include "holberton.h"

/**
 * print_char - Print a character.
 * @list: Variable.
 * @buffer: buffer
 *
 * Return: 1 (character length).
 */

void print_char(va_list list, char *buffer)
{
	char s = va_arg(list, int);

	if (!s)
	{
		_charncat(buffer, 1);
	}
	_charncat(buffer, s);
}

/**
 * print_string - Print a string.
 * @list: Variable.
 *
 * @buffer: buffer
 * Return: String length.
 */

void print_string(va_list list, char *buffer)
{
	char *str;

	str = va_arg(list, char *);
	if (!str)
	{
		str = "(null)";
	}
	_strncat(buffer, str, _strlen(str));
}

/**
 * print_percent - Print percent character.
 * @list: Variable.
 * @buffer: buffer
 *
 * Return: 1 (percent length).
 */

void print_percent(__attribute__((unused))va_list list, char *buffer)
{
	_charncat(buffer, '%');
}

/**
 * print_number - Print a Number.
 * @list: Variable.
 * @buffer: buffer
 *
 * Return: Number length.
 */

void print_number(va_list list, char *buffer)
{
	int b, m, n;
	unsigned int c;

	b = 10;
	n = va_arg(list, int);

	if (n >= 0 && n < 10)
	{
		_charncat(buffer, n + '0');
	}
	else if (n < 0 && n > -10)
	{
		n *= -1;
		_charncat(buffer, '-');
		_charncat(buffer, n + '0');
	}
	else
	{
		if (n < 0)
		{
			n *= -1;
			_charncat(buffer, '-');
		}
		c = n;
		while (c / b > 9)
		{
			b *= 10;
		}
		while (b > 0)
		{
			m = c / b;
			c %= b;
			_charncat(buffer, m + '0');
			b /= 10;
		}
	}
}
