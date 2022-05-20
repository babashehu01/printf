#include "main.h"

/**
 * l_modifier - check for l length modifiers
 * @args: Argument list
 * @c: Len specifier
 * @num_char: Number of characters printed
 * @i: Count variable in format string
 * @_c: Format specifers
 */
void l_modifier(va_list args, char c, int *num_char, int *i, char _c)
{
	int p = 0;

	if (c == 'l')
	{
		if (_c == 'd' || _c == 'i')
		{
			(*num_char) += write_int_long(va_arg(args, long int), &p);
			(*i) += 2;
			p = 0;
		}
		else if (_c == 'u')
		{
			(*num_char) += write_uint_long(va_arg(args,
						unsigned long int), &p);
			(*i) += 2;
			p = 0;

		}
		else if (_c == 'o')
		{
			(*num_char) += octal_write_long(va_arg(args,
						unsigned long int), &p);
			(*i) += 2;
			p = 0;
		}
		else if (_c == 'x')
		{
			(*num_char) += hexa_write_long(va_arg(args,
						unsigned long int), &p);
			(*i) += 2;
			p = 0;
		}
		else if (_c == 'X')
		{
			(*num_char) += hexa_x_write_long(va_arg(args,
						unsigned long int), &p);
			(*i) += 2;
			p = 0;
		}
	}
}

/**
 * h_modifier - Check for h length modifier
 * @args: Argument list
 * @c: Length modifier
 * @num_char: Number of characters
 * @i: counted variable in format string
 * @_c: Format specifier
 *
 */
void h_modifier(va_list args, char c, int *num_char, int *i, char _c)
{
	int p = 0;

	if (c == 'h')
	{
		if (_c == 'd' || _c == 'i')
		{
			(*num_char) += write_int_short(va_arg(args, int), &p);
			(*i) += 2;
			p = 0;
		}
		else if (_c == 'u')
		{
			(*num_char) += write_uint_short(va_arg(args, int), &p);
			(*i) += 2;
			p = 0;

		}
		else if (_c == 'o')
		{
			(*num_char) += octal_write_short(va_arg(args, int), &p);
			(*i) += 2;
			p = 0;
		}
		else if (_c == 'x')
		{
			(*num_char) += hexa_write_short(va_arg(args, int), &p);
			(*i) += 2;
			p = 0;
		}
		else if (_c == 'X')
		{
			(*num_char) += hexa_x_write_short(va_arg(args, int), &p);
			(*i) += 2;
			p = 0;
		}
	}
}

/**
 * length_modifiers - Check for length modifiers
 * @args: Argument list
 * @c: Length modifier
 * @num_char: Number of chars printed
 * @i: Count variable in format string
 * @_c: Format specifier
 */
void length_modifiers(va_list args, char c, int *num_char, int *i, char _c)
{
	char pc = '%';

	if (c == 'l')
	{
		if (_c == '\n')
		{
			write(1, &pc, 1);
			(*num_char)++;
			(*i)++;
			return;
		}
		l_modifier(args, c, num_char, i, _c);
		return;
	}
	if (c == 'h')
	{
		if (_c == '\n')
		{
			write(1, &pc, 1);
			(*num_char)++;
			(*i)++;
			return;
		}
		h_modifier(args, c, num_char, i, _c);
		return;
	}
}
