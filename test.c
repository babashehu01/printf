#include <stdio.h>

/**
 * main - test function
 *
 *
 */
int main(void)
{
	char s[] = "Helloi\n";
	int i = 0;

	for (i = 0; s[i]; i++)
		printf("%c, %d\n", s[i], s[i]);
}
