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
	char c = '%';
	va_list args;

	if (format == NULL)
		return (-1);
	len = _strlen(format);
	if (format[0] == '%' && len == 1)
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && len == 2)
		return (-1);
	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%' && (check_mode(format[i + 1]) ||
					check_width(format[i + 1])))
		{
			ctrl_center(args, format[i + 1], &num_char, &i,
					format[i + 2], format[i + 3]);
		}
		else if (format[i] == '%' && (check_flag(format[i + 1])
					&& check_flag(format[i + 2])))
		{
			if (format[i + 1] == '+' || format[i + 2] == '+')
				c = '+';
			check_func_flag(args, c, format[i + 3], &num_char, &i), i++;
		}
		else if (format[i] == '%' && check_flag(format[i + 1]))
		{
			check_func_flag(args, format[i + 1], format[i + 2], &num_char, &i);
		}
		else
		{
			write(1, &format[i], 1), num_char++;
		}
	}
	va_end(args);
	return (num_char);
}
