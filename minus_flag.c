#include "main.h"


/**
 * minus_flag1 - Handle (-) flag
 * @args: Argument list
 * @c: Field width
 * @num_char: Pointer to number of characters printed
 * @i: Pointer to variable format string
 * @_c: Format specifiers
 *
 */
void minus_flag1(va_list args, char c, int *num_char, int *i, char _c)
{
	int width = c - '0', num, len, p = 0;
	unsigned int numu;

	if (_c == 'd' || _c == 'i')
	{
		num = va_arg(args, int);
		len = len_int(num, &p), p = 0;
		if (width > len)
		{
			(*num_char) += width;
			write_int(num, &p);
		}
		else
		{
			(*num_char) += write_int(num, &p);
		}
		print_space(len, width);
		(*i) += 3, p = 0;
	}
	else if (_c == 'u')
	{
		numu = va_arg(args, unsigned int);
		len = len_uint(numu, &p), p = 0;
		if (width > len)
		{
			(*num_char) += width;
			write_uint(numu, &p);
		}
		else
		{
			(*num_char) += write_uint(numu, &p);
		}
		print_space(len, width);
		(*i) += 3, p = 0;
	}
}



/**
 * minus_flag2 - Handle (-) flag
 * @args: Argument list
 * @c: Field width
 * @num_char: Pointer to number of characters printed
 * @i: Pointer to variable format string
 * @_c: Format specifiers
 *
 */
void minus_flag2(va_list args, char c, int *num_char, int *i, char _c)
{
	int width = c - '0', len, p = 0;
	unsigned int numu;

	if (_c == 'o')
	{
		numu = va_arg(args, unsigned int);
		len = len_write_oct(numu, &p), p = 0;
		if (width > len)
		{
			(*num_char) += width;
			octal_write(numu, &p);
		}
		else
		{
			(*num_char) += octal_write(numu, &p);
		}
		print_space(len, width);
		(*i) += 3, p = 0;
	}
	else if (_c == 'x')
	{
		numu = va_arg(args, unsigned int);
		len = len_write_hexa(numu, &p), p = 0;
		if (width > len)
		{
			(*num_char) += width;
			hexa_write(numu, &p);
		}
		else
		{
			(*num_char) += hexa_write(numu, &p);
		}
		print_space(len, width);
		(*i) += 3, p = 0;
	}
}


/**
 * minus_flag3 - Handle (-) flag
 * @args: Argument list
 * @c: Field width
 * @num_char: Pointer to number of characters printed
 * @i: Pointer to variable format string
 * @_c: Format specifiers
 *
 */
void minus_flag3(va_list args, char c, int *num_char, int *i, char _c)
{
	unsigned int num;
	int width = c - '0', len, p = 0;

	if (_c == 'X')
	{
		num = va_arg(args, unsigned int);
		len = len_x_write(num, &p), p = 0;
		if (width > len)
		{
			(*num_char) += width;
			hexa_x_write(num, &p);
		}
		else
		{
			(*num_char) += hexa_x_write(num, &p);
		}
		print_space(len, width);
		(*i) += 3, p = 0;
	}
}


/**
 * minus_flag - Handles (-) flag
 * @args: Argument list
 * @c: Field width
 * @num_char: Pointer to number of characters printed
 * @i: pointer to variable format string
 * @_c: Format specifier
 */
void minus_flag(va_list args, char c, int *num_char, int *i, char _c)
{
	if (_c == 'd' || _c == 'i' || _c == 'u')
	{
		minus_flag1(args, c, num_char, i, _c);
	}
	else if (_c == 'o' || _c == 'x')
	{
		minus_flag2(args, c, num_char, i, _c);
	}
	else if (_c == 'X')
	{
		minus_flag3(args, c, num_char, i, _c);
	}
}
