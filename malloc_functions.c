#include "holberton.h"

/**
 * _charncat - Function that concatenates two strings.
 * @dest: String destination.
 * @src: Source String.
 *
 * Return: dest.
 */

char *_charncat(char *dest, char src)
{
	int a;

	a = 0;

	while (dest[a] != '\0')
	{
		a++;
	}
	dest[a] = src;
	dest[++a] = 0;
	return (dest);
}

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
 * free_buffer - writes the character c to stdout
 * @buffer: The character to print
 *
 * Return: nothing
 */
void free_buffer(char *buffer)
{
	int len = _strlen(buffer);
	int i;

	for (i = 0; i < len; i++)
	{
		buffer[i] = 0;
	}
	free(buffer);
}
