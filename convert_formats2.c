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

/**
 * root13 - Print a character.
 * @list: Variable.
 * @buffer: buffer
 *
 * Return: 1 (character length).
 */

void root13(va_list list, char *buffer)
{
	int i;
	char *s = va_arg(list, char*);
	char *root = malloc(_strlen(s));

	_strncat(root, s, _strlen(s));

	for (i = 0; root[i]; i++)
	{
		if (root[i] <= 109 && root[i] >= 97)
			root[i] += 13;
		else if (root[i] > 109 && root[i] < 123)
			root[i] -= 13;
	}
	_strncat(buffer, root, _strlen(root));
	free_buffer(root);
}
