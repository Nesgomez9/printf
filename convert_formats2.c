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
		if ((root[i] <= 109 && root[i] >= 97) || (root[i] <= 77 && root[i] >= 65))
			root[i] += 13;
		else if ((root[i] > 109 && root[i] < 123) || (root[i] < 90 && root[i] > 77))
			root[i] -= 13;
	}
	_strncat(buffer, root, _strlen(root));
	free_buffer(root);
}
/**
 * hex_string - Print a string.
 * @s: Variable.
 *
 * Return: String length.
 */

char *hex_string(char s)
{
	char *str = malloc(5);
	int a = s;
	int i = 0;

	str[i++] = '\\';
	str[i++] = 'x';

	if (s <= 15)
	{
		str[i++] = '0';
	}
	if (a % 16 < 10)
		str[i++] = a % 16 + '0';
	if (a % 16 >= 10)
		str[i++] = a % 16 + '7';
	a /= 16;
	if (a < 10 && a > 0)
		str[i++] = a + '0';
	if (a >= 10)
		str[i++] = a + '7';
	str[i++] = 0;
	return (str);
}
/**
 * print_String - Print a string.
 * @list: Variable.
 *
 * @buffer: buffer
 * Return: String length.
 */

void print_String(va_list list, char *buffer)
{
	int i;
	char *str;
	char *dest;

	str = va_arg(list, char *);
	if (!str)
	{
		str = "(null)";
	}
	i = 0;
	while (str[i])
	{
		if ((str[i] > 0 && str[i] < 32) || str[i] >= 127)
		{
			dest = hex_string(str[i]);
			_strncat(buffer, dest, _strlen(dest));
			free_buffer(dest);
		}
		else
		{
			_charncat(buffer, str[i]);
		}
		i++;
	}
}
