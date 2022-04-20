#include "main.h"

/**
 * _printf - prints a formatted output
 * @format: is a character string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, str_len;
	int num_char = 0;
	char *s, w, n = '\n';
	va_list args;

	if (!format)
		return (-1);
	va_start(args, format);

	for (i = 0; format[i]; i++)
	{
	if (format[i] == '%')
	{
		if (format[i + 1] == 's')
		{
			s = va_arg(args, char *);
			str_len = _strlen(s);
			write(1, s, str_len);
			num_char += str_len, i++;
		}
		else if (format[i + 1] == 'c')
		{
			w = va_arg(args, int);
			write(1, &w, 1);
			num_char++, i++;
		}
		else if (format[i + 1] == 'd' || format[i + 1] == 'i')
		{
			write_int(va_arg(args, int));
			i++;
		}
		else if (format[i + 1] == 'b')
		{
			bin(va_arg(args, int));
			i++;
		}
	}
	else if (format[i] == '\n')
	{
		write(1, &n, 1);
		num_char++;
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
