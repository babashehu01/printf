#include "main.h"


/**
 * field_width1 - Handle field width
 * @args: Argument list
 * @c: Field width
 * @num_char: Pointer to number of characters printed
 * @i: Pointer to variable format string
 * @_c: Format specifiers
 *
 */
void field_width1(va_list args, char c, int *num_char, int *i, char _c)
{
	int width = c - '0', num, len, p = 0;
	unsigned int numu;

	if (_c == 'd' || _c == 'i')
	{
		num = va_arg(args, int);
		len = len_int(num, &p), p = 0;
		print_space(len, width);
		if (width > len)
		{
			(*num_char) += width;
			write_int(num, &p);
		}
		else
		{
			(*num_char) += write_int(num, &p);
		}
		(*i) += 2, p = 0;
	}
	else if (_c == 'u')
	{
		numu = va_arg(args, unsigned int);
		len = len_uint(numu, &p), p = 0;
		print_space(len, width);
		if (width > len)
		{
			(*num_char) += width;
			write_uint(numu, &p);
		}
		else
		{
			(*num_char) += write_uint(numu, &p);
		}
		(*i) += 2, p = 0;
	}
}



/**
 * field_width2 - Handle field width
 * @args: Argument list
 * @c: Field width
 * @num_char: Pointer to number of characters printed
 * @i: Pointer to variable format string
 * @_c: Format specifiers
 *
 */
void field_width2(va_list args, char c, int *num_char, int *i, char _c)
{
	int width = c - '0', num, len, p = 0;
	unsigned int numu;

	if (_c == 'o')
	{
		num = va_arg(args, unsigned int);
		len = len_write_oct(num, &p), p = 0;
		print_space(len, width);
		if (width > len)
		{
			(*num_char) += width;
			octal_write(num, &p);
		}
		else
		{
			(*num_char) += octal_write(num, &p);
		}
		(*i) += 2, p = 0;
	}
	else if (_c == 'x')
	{
		numu = va_arg(args, unsigned int);
		len = len_write_hexa(numu, &p), p = 0;
		print_space(len, width);
		if (width > len)
		{
			(*num_char) += width;
			hexa_write(numu, &p);
		}
		else
		{
			(*num_char) += hexa_write(numu, &p);
		}
		(*i) += 2, p = 0;
	}
}



/**
 * field_width3 - Handle field width
 * @args: Argument list
 * @c: Field width
 * @num_char: Pointer to number of characters printed
 * @i: Pointer to variable format string
 * @_c: Format specifiers
 *
 */
void field_width3(va_list args, char c, int *num_char, int *i, char _c)
{
	int width = c - '0', num, len, p = 0;

	if (_c == 'X')
	{
		num = va_arg(args, int);
		len = len_x_write(num, &p), p = 0;
		print_space(len, width);
		if (width > len)
		{
			(*num_char) += width;
			hexa_x_write(num, &p);
		}
		else
		{
			(*num_char) += hexa_x_write(num, &p);
		}
		(*i) += 2, p = 0;
	}
}


/**
 * field_width - Handles field width
 * @args: Argument list
 * @c: Field width
 * @num_char: Pointer to number of characters printed
 * @i: pointer to variable format string
 * @_c: Format specifier
 */
void field_width(va_list args, char c, int *num_char, int *i, char _c)
{
	if (_c == 'd' || _c == 'i' || _c == 'u')
	{
		field_width1(args, c, num_char, i, _c);
	}
	else if (_c == 'o' || _c == 'x')
	{
		field_width2(args, c, num_char, i, _c);
	}
	else if (_c == 'X')
	{
		field_width3(args, c, num_char, i, _c);
	}
}
