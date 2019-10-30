#include "holberton.h"
#include <unistd.h>

/**
 * _strncat - Function that concatenates two strings.
 * @dest: String destination.
 * @src: Source String.
 * @n: int.
 *
 * Return: dest.
 */

char *_strncat(char *dest, char *src, int n)
{
	int a, b;

	a = 0;
	b = 0;

	while (dest[a] != '\0')
	{
		a++;
	}
	while (b < n)
	{
		dest[a] = src[b];
		a++;
		b++;
	}
	return (dest);
}

/**
 * _strlen - writes the character c to stdout
 * @s: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _strlen(char *s)
{
	int i = 0;

        while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * rev_string - writes the character c to stdout
 * @s: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

void rev_string(char *s)
{
	int i = 0;
	char temp;
	int j, len;

	while (s[i] != '\0')
	{
		i++;
	}

	i -= 1;
	len = i;
	if (i % 2 == 0)
	{
		for (j = 0; j < len / 2; j++)
		{
			temp = s[j];
			s[j] = s[i];
			s[i] = temp;
			i--;
		}
	}
	else
	{
		for (j = 0; j <= len / 2; j++)
		{
			temp = s[j];
			s[j] = s[i];
			s[i] = temp;
			i--;
		}
	}
}
