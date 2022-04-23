#include "main.h"

/**
 * _printf - prints a formatted output
 * @format: is a character string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, p = 0;
	int num_char = 0;
	va_list args;

	if (!format)
		return (-1);
	va_start(args, format);

	for (i = 0; format[i]; i++)
	{
	if (format[i] == '%' && check_mode(format[i + 1]))
	{
		if (format[i + 1] == 's')
		{
			num_char += write_str(va_arg(args, char *));
			i++;
		}
		else if (format[i + 1] == 'c')
		{
			num_char += write_char(va_arg(args, int));
			i++;
		}
		else if (format[i + 1] == 'd' || format[i + 1] == 'i')
		{
			num_char += write_int(va_arg(args, int), &p);
			i++;
		}
		else if (format[i + 1] == 'b')
		{
			num_char += bin(va_arg(args, int), &p);
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
