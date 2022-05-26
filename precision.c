#include "main.h"

void precision1_(int width, int len, int *num_char, int *i, unsigned int numU);

/**
 * precision1 - Handle precison specifier
 * @args: Arguments Lists
 * @c: Prcision value
 * @num_char: Pointer to number of characters printed
 * @i: Pointer to count variable format string
 * @_c: Format specifier
 *
 */
void precision1(va_list args, char c, int *num_char, int *i, char _c)
{
	unsigned int numU;
	int width = c - '0', num, len, p = 0;
	char j = '-';

	if (c == '*')
		width = va_arg(args, int);
	if (_c == 'd' || _c == 'i')
	{
		num = va_arg(args, int);
		if (width == 0 && num == 0)
		{
			(*i) += 3;
			return;
		}
		len = len_int(num, &p), p = 0;
		if (num < 0)
			write(1, &j, 1), num = -num, len--, (*num_char)++;
		print_zero(len, width);
		if (width > len)
		{
			(*num_char) += width, write_int(num, &p);
		}
		else
		{
			(*num_char) += write_int(num, &p);
		}
		(*i) += 3, p = 0;
	}
	else if (_c == 'u')
	{
		numU = va_arg(args, unsigned int);
		if (width == 0 && numU == 0)
		{
			(*i) += 3;
			return;
		}
		len  = len_uint(numU, &p), p = 0, print_zero(len, width);
		precision1_(width, len, num_char, i, numU);
	}
}

/**
 * precision1_ - Handles (.) for u
 * @width: width
 * @len: Number of digits
 * @num_char: Pointer to number of variables printed
 * @i: count variable
 * @numU: unsigned int
 *
 */
void precision1_(int width, int len, int *num_char, int *i, unsigned int numU)
{
	int p = 0;

	if (width > len)
	{
		(*num_char) += width;
		write_uint(numU, &p);
	}
	else
	{
		(*num_char) += write_uint(numU, &p);
	}
	(*i) += 3, p = 0;
}


/**
 * precision2 - Handle precison specifier
 * @args: Arguments Lists
 * @c: Prcision value
 * @num_char: Pointer to number of characters printed
 * @i: Pointer to count variable format string
 * @_c: Format specifier
 *
 */
void precision2(va_list args, char c, int *num_char, int *i, char _c)
{
	unsigned int numU;
	int width = c - '0', len, p = 0;

	if (c == '*')
		width = va_arg(args, int);
	numU = va_arg(args, unsigned int);
	if (width == 0 && numU == 0)
	{
		(*i) += 3;
		return;
	}
	if (_c == 'o')
	{
		len = len_write_oct(numU, &p), p = 0, print_zero(len, width);
		if (width > len)
		{
			(*num_char) += width, octal_write(numU, &p);
		}
		else
		{
			(*num_char) += octal_write(numU, &p);
		}
		(*i) += 3, p = 0;
	}
	else if (_c == 'x')
	{
		len  = len_write_hexa(numU, &p), p = 0, print_zero(len, width);
		if (width > len)
		{
			(*num_char) += width, hexa_write(numU, &p);
		}
		else
		{
			(*num_char) += hexa_write(numU, &p);
		}
		(*i) += 3, p = 0;
	}
}



/**
 * precision3 - Handle precison specifier
 * @args: Arguments Lists
 * @c: Prcision value
 * @num_char: Pointer to number of characters printed
 * @i: Pointer to count variable format string
 * @_c: Format specifier
 *
 */
void precision3(va_list args, char c, int *num_char, int *i, char _c)
{
	unsigned int numU;
	int width = c - '0', len, p = 0;
	char *str;

	if (c == '*')
		width = va_arg(args, int);
	if (_c == 'X')
	{
		numU = va_arg(args, unsigned int);
		if (width == 0 && numU == 0)
		{
			(*i) += 3;
			return;
		}
		len = len_x_write(numU, &p), p = 0, print_zero(len, width);
		if (width > len)
		{
			(*num_char) += width, hexa_x_write(numU, &p);
		}
		else
		{
			(*num_char) += hexa_x_write(numU, &p);
		}
		(*i) += 3, p = 0;
	}
	else if (_c == 's')
	{
		str = va_arg(args, char *), len = _strlen(str);
		if (width < len)
			(*num_char) += write_str1(str, width);
		else
			(*num_char) += write_str(str);
		(*i) += 3;
	}
}


/**
 * precision - Handle the right function for format specifier
 * @args: Argument list
 * @c: Precision value
 * @num_char: Pointer to number of chars printed
 * @i: Pointer to variable format string
 * @_c: Format specifiers
 *
 */
void precision(va_list args, char c, int *num_char, int *i, char _c)
{
	if (_c == 'd' || _c == 'i' || _c == 'u')
		precision1(args, c, num_char, i, _c);
	else if (_c == 'o' || _c == 'x')
		precision2(args, c, num_char, i, _c);
	else if (_c == 'X' || _c == 's')
		precision3(args, c, num_char, i, _c);
}
