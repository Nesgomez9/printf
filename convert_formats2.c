#include "holberton.h"

/**
 * Hex - Print a character.
 * @list: Variable.
 * @buffer: buffer
 *
 * Return: 1 (character length).
 */

void Hex(va_list list, char *buffer)
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
		if (c % 16 < 10)
			s[i] = c % 16 + '0';
		else
			s[i] = c % 16 + '7';
		c /= 16;
	}
	if (c % 16 < 10)
		s[i] = c % 16 + '0';
	else
		s[i] = c % 16 + '7';
	s[++i] = 0;
	rev_string(s);
	_strncat(buffer, s, _strlen(s));
	free(s);
}
