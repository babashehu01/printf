#include "main.h"

/**
 * wrt_flag - Write integers
 * @num: Number
 * @c: Character passed
 * @num_char: Number of chars printed
 * @i: Count variable
 */
void wrt_flag(int num, char c, int *num_char, int *i)
{
	int p = 0;

	if (num >= 0)
	{
		write(1, &c, 1);
		(*num_char)++;
	}
	(*num_char) += write_int(num, &p);
	(*i) += 1;
}

/**
 * wrt_flag1 - Write integers in different number system
 * @num: Unsigned int
 * @num_char: Number of chars printed
 * @i: Count variable
 * @func: Function pointer
 */
void wrt_flag1(unsigned int num, int *num_char,
		int *i, int (*func)(unsigned int, int *))
{
	int p = 0;
	char c = '0';

	if (num == 0)
	{
		write(1, &c, 1);
		(*num_char)++;
		(*i) += 2;
		return;
	}
	write(1, &c, 1);
	(*num_char) += (func(num, &p) + 1);
	(*i) += 1;
}


/**
 * wrt_flag2 - Write integers in different number system
 * @num: Unsigned int
 * @str: string passed
 * @num_char: Number of chars printed
 * @i: Count variable
 * @func: Function pointer
 */
void wrt_flag2(unsigned int num, char *str, int *num_char,
		int *i, int (*func)(unsigned int, int *))
{
	int p = 0;
	char c = '0';

	if (num == 0)
	{
		write(1, &c, 1);
		(*num_char)++;
		(*i) += 2;
		return;
	}
	write(1, str, 2);
	(*num_char) += (func(num, &p) + 2);
	(*i) += 1;
}

/**
 * check_func_flag - Picks function with right flag
 * @args: Arguments of va_list
 * @num_char: Number of chars printed
 * @i: count variable
 * @c: Flag
 * @f_spec: Format specifier
 */
void check_func_flag(va_list args, char c, char f_spec, int *num_char, int *i)
{
	char *s = "0x", *s1 = "0X",  *s2 = "% ";

	(*i)++;
	if (c == '+' && (f_spec == 'd' || f_spec == 'i'))
	{
		wrt_flag(va_arg(args, int), c, num_char, i);
	}
	else if (c == ' ' && (f_spec == 'd' || f_spec == 'i'))
	{
		wrt_flag(va_arg(args, int), c, num_char, i);
	}
	else if (c == '#')
	{
		if (f_spec == 'o')
		{
			wrt_flag1(va_arg(args, unsigned int), num_char, i, &octal_write);
		}
		else if (f_spec == 'x')
		{
			wrt_flag2(va_arg(args, unsigned int), s, num_char, i, &hexa_write);
		}
		else if (f_spec == 'X')
		{
			wrt_flag2(va_arg(args, unsigned int), s1, num_char, i, &hexa_x_write);
		}
	}
	else if (c == '%')
	{
		write(1, s2, 2);
		(*num_char) += 2;
		(*i) += 1;
	}

}
