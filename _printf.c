#include "main.h"

/**
 * _printf - prints a formatted output
 * @format: is a character string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	int len, i, num_char = 0;
	va_list args;

	if (format == NULL)
		return (-1);
	len = _strlen(format);

	if (format[0] == '%' && len == 1)
		return (-1);
	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
	if (format[i] == '%' && check_mode(format[i + 1]))
	{
		check_func(args, format[i + 1], &num_char, &i);
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
