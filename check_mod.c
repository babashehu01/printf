#include "main.h"
/**
 * check_mode - checks for a ('%') symbol
 * @c: inputed character
 *
 * Return: state of the func
 */
int check_mode(char c)
{
	int i;
	char arr[] = "RrlhpSXxoucsdib\n%";

	for (i = 0; arr[i]; i++)
	{
		if (arr[i] == c)
			return (1);
		if (c == '\0')
			return (1);
	}
	return (0);
}

/**
 * check_width - Check field width
 * @c: Inputed character
 *
 * Return: state of func
 */
int check_width(char c)
{
	if (c == '*')
		return (1);
	if (c == '.')
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	if (c == '-')
		return (1);
	return (0);
}


/**
 * print_space - Print space to standard output
 * @len: Number of digits
 * @width: Width
 *
 */
void print_space(int len, int width)
{
	char c = ' ';

	while (len < width)
	{
		write(1, &c, 1);
		len++;
	}
}


/**
 * print_zero - Print zero to standard output
 * @len: Number of digits
 * @width: Width
 *
 */
void print_zero(int len, int width)
{
	char c = '0';

	while (len < width)
	{
		write(1, &c, 1);
		len++;
	}
}
