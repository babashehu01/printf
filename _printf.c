#include "main.h"

/**
 * _printf - prints a formatted string
 * @format: string formats to be printed
 *
 * Return: Always 0 (Success)
 */
int _printf(const char *format, ...)
{
	int i = 0;
	int count = 0;
	va_list valist;

	va_start(valist, format);

	if (!format)
		return (-1);
	for (i = 0; format[i]; i++)
	{
		if (format[i] != '%')
		{
			count++;
			_putchar(format[i]);
		}
		else if (format[i + 1])
		{
			i++;
			count = _withformat(format[i], count, valist);
		}
		else
			return (-1);
	}
	va_end(valist);
	return (count);
}
