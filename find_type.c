#include "holberton.h"

/**
 * find_type - Find format.
 * @format: Variable.
 * @type: Types.
 * @list: Args.
 *
 * Return: lengh.
 */

int find_type(const char *format, format_t type[], va_list list)
{
	int i, j, print = 0;
	char *buffer = malloc(2048);

	if (!buffer)
		return (0);

	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; type[j].f1; j++)
			{
				if (format[i + 1] == type[j].f1[0])
				{
					type[j].f2(list, buffer);
					break;
				}
			}
			if (!type[j].f1)
			{
				if (format[i + 1] != '\0')
				{
					_charncat(buffer, '%');
					_charncat(buffer, format[i + 1]);
				}
				else
					return (-1);
			}
			i++;
		}
		else
		{
			_charncat(buffer, format[i]);
			print++;
		}
	}
	write(1, buffer, _strlen(buffer));
	print = _strlen(buffer);
	free_buffer(buffer);
	return (print);
}
