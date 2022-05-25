#include "main.h"

/**
 * ctrl_center - Handles the right function
 * @args: Argument list
 * @c: Format specifier, length midifiers, field widths
 * @num_char: Pointer to number of characters printed
 * @i: Count variable in format string
 * @_c: Format specifier in some cases
 *
 */
void ctrl_center(va_list args, char c, int *num_char, int *i, char _c)
{
	if (c == 's' || c == 'c' || c == 'd' || c == 'i' || c == 'b' || c == '%')
		check_func(args, c, num_char, i);
	else if (c == 'u' || c == 'o' || c == 'x' || c == 'X' || c == 'S' || c == 'p')
		check_func2(args, c, num_char, i);
	else if (c == 'l' || c == 'h')
		length_modifiers(args, c, num_char, i, _c);
	else if (check_width(c))
		field_width(args, c, num_char, i, _c);
}
