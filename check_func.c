#include "main.h"
/**
 * check_func - checks for the correct specifier to use
 * @args: arguement of va_list
 * @c: format
 * @num_char: number of chars printed
 * @i: count variable
 *
 * Return: No return value
 */

void check_func(va_list args, char c, int *num_char, int *i)
{
	int p = 0;

	if (c == 's')
	{
		(*num_char) += write_str(va_arg(args, char *));
		(*i)++;
	}
	else if (c == 'c')
	{
		(*num_char) += write_char(va_arg(args, int));
		(*i)++;
	}
	else if (c == 'd' || c == 'i')
	{
		(*num_char) += write_int(va_arg(args, int), &p);
		(*i)++, p = 0;
	}
	else if (c == 'b')
	{
		(*num_char) += bin(va_arg(args, int), &p);
		(*i)++;
		p = 0;
	}
	else if (c == '%' && check_mode(c))
	{
		write(1, &c, 1);
		(*num_char)++;
		(*i)++;
	}
}
