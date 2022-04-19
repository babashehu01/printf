#include "main.h"
#include <stdio.h>

/**
 * _printf - prints a formatted output
 * @format: is a character string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	if (format)
	{
		va_list args;

		va_start(args, format);

		int i, length, str_len, num_char = 0;

		length = _strlen(format);

		for (i = 0; i < length; i++)
		{
			if (format[i] == '%')
			{
				if (format[i + 1] == 's')
				{
					char *s = va_arg(args, char *);

					str_len = _strlen(s);
					write(1, s, str_len);
					num_char += str_len;
					i++;
				}
				else if (format[i + 1] == 'c')
				{
					char w = va_arg(args, int);

					write(1, &w, 1);
					num_char++;
					i++;
				}
			}
			else
			{
				write(1, &format[i], 1);
			}
		}
		va_end(args);
		return (num_char);
	}
}
