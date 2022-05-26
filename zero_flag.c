#include "main.h"


/**
 * zero_flag1 - Handle field width
 * @args: Argument list
 * @c: Field width
 * @num_char: Pointer to number of characters printed
 * @i: Pointer to variable format string
 * @_c: Format specifiers
 *
 */
void zero_flag1(va_list args, char c, int *num_char, int *i, char _c)
{
	int width = c - '0', num, temp, len, p = 0;
	unsigned int numu;
	char k = '-';

	if (_c == 'd' || _c == 'i')
	{
		num = va_arg(args, int);
		temp = num;
		len = len_int(num, &p), p = 0;
		if (num < 0)
			write(1, &k, 1), num = -num, (*num_char)++;
		print_zero(len, width);
		if (width > len)
		{
			if (temp < 0)
				(*num_char) += width - 1;
			else
				(*num_char) += width;
			write_int(num, &p);
		}
		else
		{
			(*num_char) += write_int(num, &p);
		}
		(*i) += 3, p = 0;
	}
	else if (_c == 'u')
	{
		numu = va_arg(args, unsigned int);
		len = len_uint(numu, &p), p = 0;
		print_zero(len, width);
		if (width > len)
		{
			(*num_char) += width;
			write_uint(numu, &p);
		}
		else
		{
			(*num_char) += write_uint(numu, &p);
		}
		(*i) += 3, p = 0;
	}
}



/**
 * zero_flag2 - Handle field width
 * @args: Argument list
 * @c: Field width
 * @num_char: Pointer to number of characters printed
 * @i: Pointer to variable format string
 * @_c: Format specifiers
 *
 */
void zero_flag2(va_list args, char c, int *num_char, int *i, char _c)
{
	int width = c - '0', len, p = 0;
	unsigned int numu;

	if (_c == 'o')
	{
		numu = va_arg(args, unsigned int);
		len = len_write_oct(numu, &p), p = 0;
		print_zero(len, width);
		if (width > len)
		{
			(*num_char) += width;
			octal_write(numu, &p);
		}
		else
		{
			(*num_char) += octal_write(numu, &p);
		}
		(*i) += 3, p = 0;
	}
	else if (_c == 'x')
	{
		numu = va_arg(args, unsigned int);
		len = len_write_hexa(numu, &p), p = 0;
		print_zero(len, width);
		if (width > len)
		{
			(*num_char) += width;
			hexa_write(numu, &p);
		}
		else
		{
			(*num_char) += hexa_write(numu, &p);
		}
		(*i) += 3, p = 0;
	}
}


/**
 * zero_flag3 - Handle field width
 * @args: Argument list
 * @c: Field width
 * @num_char: Pointer to number of characters printed
 * @i: Pointer to variable format string
 * @_c: Format specifiers
 *
 */
void zero_flag3(va_list args, char c, int *num_char, int *i, char _c)
{
	unsigned int num;
	int width = c - '0', len, p = 0;

	if (_c == 'X')
	{
		num = va_arg(args, unsigned int);
		len = len_x_write(num, &p), p = 0;
		print_zero(len, width);
		if (width > len)
		{
			(*num_char) += width;
			hexa_x_write(num, &p);
		}
		else
		{
			(*num_char) += hexa_x_write(num, &p);
		}
		(*i) += 3, p = 0;
	}
}


/**
 * zero_flag - Handles field width
 * @args: Argument list
 * @c: Field width
 * @num_char: Pointer to number of characters printed
 * @i: pointer to variable format string
 * @_c: Format specifier
 */
void zero_flag(va_list args, char c, int *num_char, int *i, char _c)
{
	if (_c == 'd' || _c == 'i' || _c == 'u')
	{
		zero_flag1(args, c, num_char, i, _c);
	}
	else if (_c == 'o' || _c == 'x')
	{
		zero_flag2(args, c, num_char, i, _c);
	}
	else if (_c == 'X' || _c == 'c')
	{
		zero_flag3(args, c, num_char, i, _c);
	}
}
