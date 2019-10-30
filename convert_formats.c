#include "holberton.h"

/**
 * binary - Print a character.
 * @list: Variable.
 * @buffer: buffer
 *
 * Return: 1 (character length).
 */

void binary(va_list list, char *buffer)
{
	int i;
	unsigned int b;
	unsigned int c = va_arg(list, unsigned int);
	char *s;

	b = c;

	for (i = 0; b != 0 && b != 1; i++)
	{
		b /= 2;
	}
	i += 2;
	s = malloc(i);
	if (!s)
		return;
	for (i = 0; c != 0 && c != 1; i++)
	{
		s[i] = c % 2 + '0';
		c /= 2;
	}
	s[i] = c + '0';
	s[++i] = 0;
	rev_string(s);
	_strncat(buffer, s, _strlen(s));
	free(s);
}

/**
 * reverse - Print a character.
 * @list: Variable.
 * @buffer: buffer
 *
 * Return: 1 (character length).
 */

void reverse(va_list list, char *buffer)
{
	char *s = va_arg(list, char*);
	char *dest = malloc(_strlen(s));

	_strncat(dest, s, _strlen(s));
	rev_string(dest);
	_strncat(buffer, dest, _strlen(dest));
	free_buffer(dest);
}

/**
 * octal - Print a character.
 * @list: Variable.
 * @buffer: buffer
 *
 * Return: 1 (character length).
 */

void octal(va_list list, char *buffer)
{
	int i;
	unsigned int b;
	unsigned int c = va_arg(list, unsigned int);
	char *s;

	b = c;

	for (i = 0; b > 7; i++)
	{
		b /= 8;
	}
	i++;
	s = malloc(i);
	if (!s)
		return;
	for (i = 0; c > 7; i++)
	{
		s[i] = c % 8 + '0';
		c /= 8;
	}
	s[i] = c + '0';
	s[++i] = 0;
	rev_string(s);
	_strncat(buffer, s, _strlen(s));
	free(s);
}

/**
 * print_u_number - Print a character.
 * @list: Variable.
 * @buffer: buffer
 *
 * Return: 1 (character length).
 */

void print_u_number(va_list list, char *buffer)
{
	int b, m, n;
	unsigned int c;

	b = 10;
	n = va_arg(list, unsigned int);

	if (n >= 0 && n < 10)
	{
		_charncat(buffer, n + '0');
	}
	else
	{
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

/**
 * hex - Print a character.
 * @list: Variable.
 * @buffer: buffer
 *
 * Return: 1 (character length).
 */

void hex(va_list list, char *buffer)
{
	int i;
	unsigned int b;
	unsigned int c = va_arg(list, unsigned int);
	char *s;

	b = c;

	for (i = 0; b > 15; i++)
	{
		b /= 16;
	}
	i += 2;
	s = malloc(i);
	if (!s)
		return;
	for (i = 0; c > 15; i++)
	{
		if (c % 2 < 10)
			s[i] = c % 2 + '0';
		else
			s[i] = c % 2 + 'W';
		c /= 16;
	}
	s[i] = c + '0';
	s[++i] = 0;
	rev_string(s);
	_strncat(buffer, s, _strlen(s));
	free(s);
}
