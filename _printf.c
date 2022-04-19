#include "main.h"

/**
 * _printf - prints a formatted output
 * @format: is a character string
 *
 * Return: Number of characters printed
 */
int print_str(const char *format);
int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	if (format)
	{
		int i, length, str_len;
		int num_char = 0;
		char *s, w;

		length = _strlen(format);
		for (i = 0; i < length; i++)
		{
			if (format[i] == '%')
			{
				if (format[i + 1] == 's')
				{
					s = va_arg(args, char *);
					str_len = _strlen(s);
					write(1, s, str_len);
					num_char += str_len;
					i++;
				}
				else if (format[i + 1] == 'c')
				{
					w = va_arg(args, int);
					write(1, &w, 1);
					num_char++;
					i++;
				}
			}
			else
			{
				write(1, &format[i], 1);
				num_char++;
			}
		}
		va_end(args);
		return (num_char);
	}
	else
	return (-1);
}
