#include "main.h"

/**
 * wrt_address - Write the address
 * @ptr: Address passed
 *
 * Return: Length of address
 */
int wrt_address(void *ptr)
{
	unsigned long int u_num = (unsigned long int)ptr;
	char *s = "0x";
	int len = 2, i = 0;

	if (u_num == 0)
	{
		s = "(nil)";
		write(1, s, 5);
		return (5);
	}
	write(1, s, 2);
	len += hexa_ulong_write(u_num, &i);

	return (len);
}
