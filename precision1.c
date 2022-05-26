#include "main.h"

/**
 * precision4 - Handle precison specifier
 * @args: Arguments Lists
 * @c: Prcision value
 * @num_char: Pointer to number of characters printed
 * @i: Pointer to count variable format string
 * @_c: Format specifier
 *
 */
void precision4(va_list args, char c, int *num_char, int *i, char _c)
{
	unsigned int numU;
	int width = c - '0', num, len, p = 0;
	char j = '-';

	width = 0;
	if (_c == 'd' || _c == 'i')
	{
		num = va_arg(args, int);
		if (width == 0 && num == 0)
		{
			(*i) += 2;
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
		(*i) += 2, p = 0;
	}
	else if (_c == 'u')
	{
		numU = va_arg(args, unsigned int);
		if (width == 0 && numU == 0)
		{
			(*i) += 2;
			return;
		}
		len  = len_uint(numU, &p), p = 0, print_zero(len, width);
		if (width > len)
		{
			(*num_char) += width, write_uint(numU, &p);
		}
		else
		{
			(*num_char) += write_uint(numU, &p);
		}
		(*i) += 2, p = 0;
	}
}



/**
 * precision5 - Handle precison specifier
 * @args: Arguments Lists
 * @c: Prcision value
 * @num_char: Pointer to number of characters printed
 * @i: Pointer to count variable format string
 * @_c: Format specifier
 *
 */
void precision5(va_list args, char c, int *num_char, int *i, char _c)
{
	unsigned int numU;
	int width = c - '0', len, p = 0;

	width = 0;
	numU = va_arg(args, unsigned int);
	if (width == 0 && numU == 0)
	{
		(*i) += 2;
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
		(*i) += 2, p = 0;
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
		(*i) += 2, p = 0;
	}
}



/**
 * precision6 - Handle precison specifier
 * @args: Arguments Lists
 * @c: Prcision value
 * @num_char: Pointer to number of characters printed
 * @i: Pointer to count variable format string
 * @_c: Format specifier
 *
 */
void precision6(va_list args, char c, int *num_char, int *i, char _c)
{
	unsigned int numU;
	int width = c - '0', len, p = 0;
	char *str;

	width = 0;
	if (_c == 'X')
	{
		numU = va_arg(args, unsigned int);
		if (width == 0 && numU == 0)
		{
			(*i) += 2;
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
		(*i) += 2, p = 0;
	}
	else if (_c == 's')
	{
		str = va_arg(args, char *), len = _strlen(str);
		if (width < len)
			(*num_char) += write_str1(str, width);
		else
			(*num_char) += write_str(str);
		(*i) += 2;
	}
}


/**
 * precision7 - Handle the right function for format specifier
 * @args: Argument list
 * @c: Precision value
 * @num_char: Pointer to number of chars printed
 * @i: Pointer to variable format string
 * @_c: Format specifiers
 *
 */
void precision7(va_list args, char c, int *num_char, int *i, char _c)
{
	if (_c == 'd' || _c == 'i' || _c == 'u')
		precision4(args, c, num_char, i, _c);
	else if (_c == 'o' || _c == 'x')
		precision5(args, c, num_char, i, _c);
	else if (_c == 'X' || _c == 's')
		precision6(args, c, num_char, i, _c);
}
