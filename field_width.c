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

	if (c == '*')
		width = va_arg(args, int);
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
	int width = c - '0', len, p = 0;
	unsigned int numu;

	if (c == '*')
		width = va_arg(args, int);
	if (_c == 'o')
	{
		numu = va_arg(args, unsigned int);
		len = len_write_oct(numu, &p), p = 0;
		print_space(len, width);
		if (width > len)
		{
			(*num_char) += width;
			octal_write(numu, &p);
		}
		else
		{
			(*num_char) += octal_write(numu, &p);
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
	unsigned int num;
	int width = c - '0', len, p = 0;
	char k;

	if (c == '*')
		width = va_arg(args, int);
	if (_c == 'X')
	{
		num = va_arg(args, unsigned int);
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
	else if (_c == 'c')
	{
		k = va_arg(args, int);
		print_space(1, width);
		if (width > 1)
		{
			(*num_char) += width;
			write_char(k);
		}
		else
		{
			(*num_char) += write_char(k);
		}
		(*i) += 2;
	}
}

/**
 * field_width4 - Handle field width
 * @args: Argument list
 * @c: Field width
 * @num_char: Pointer to number of characters printed
 * @i: Pointer to variable format string
 * @_c: Format specifiers
 *
 */
void field_width4(va_list args, char c, int *num_char, int *i, char _c)
{
	int width = c - '0', len;
	char *str;

	if (c == '*')
		width = va_arg(args, int);
	if (_c == 's')
	{
		str = va_arg(args, char *);
		len = _strlen(str);
		print_space(len, width);
		if (width > len)
		{
			(*num_char) += width;
			write_str(str);
		}
		else
		{
			(*num_char) += write_str(str);
		}
		(*i) += 2;
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
	else if (_c == 'X' || _c == 'c')
	{
		field_width3(args, c, num_char, i, _c);
	}
	else if (_c == 's')
	{
		field_width4(args, c, num_char, i, _c);
	}
}
