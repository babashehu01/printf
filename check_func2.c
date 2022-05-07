#include "main.h"

/**
 * check_func2 - check for the correct format specifer
 * @args: Argument list
 * @c: Format specifer
 * @num_char: Number of characters printed
 * @i: count variable in format string
 */
void check_func2(va_list args, char c, int *num_char, int *i)
{
	int p = 0;

	if (c == 'u')
	{
		(*num_char) += write_uint(va_arg(args, unsigned int), &p);
		(*i)++;
		p = 0;
	}
	else if (c == 'o')
	{
		(*num_char) += octal_write(va_arg(args, unsigned int), &p);
		(*i)++;
		p = 0;
	}
	else if (c == 'x')
	{
		(*num_char) += hexa_write(va_arg(args, unsigned int), &p);
		(*i)++;
		p = 0;
	}
	else if (c == 'X')
	{
		(*num_char) += hexa_x_write(va_arg(args, unsigned int), &p);
		(*i)++;
		p = 0;
	}
	else if (c == 'S')
	{
		(*num_char) += str_ascii(va_arg(args, char *));
		(*i)++;
	}
	else if (c == 'p')
	{
		(*num_char) += wrt_address(va_arg(args, void *));
		(*i)++;
	}
}
