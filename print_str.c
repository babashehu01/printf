#include "main.h"

/**
 * print_str - writes a string to stdout
 * @format: string to be written
 * Return: No return value
 */
int print_str(const char *format)
{
	int length;

	length = _strlen(format);
	write(1, format, length + 1);

	return (length);
}
