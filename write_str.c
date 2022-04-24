#include "main.h"

int write_str(char *s)
{
	int length;

	if (s == (char *)0)
	{
		s = "(null)";
		write(1, s, 6);
		return (6);
	}
	length = _strlen(s);

	write(1, s, length);
	return (length);
}
