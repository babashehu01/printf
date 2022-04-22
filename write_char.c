#include "main.h"

int write_char(char c)
{
	write(1, &c, 1);
	return (1);
}
