#include "header.h"
#include <string.h>

int		toInt(char *bits)
{
	int decimal = 0;
	int base = 1;
	int len = strlen(bits);

	for (int i = len-1; i >= 0; i--)
	{
		if (bits[i] == '1')
			decimal += base;
		base *= 2;
	}
	return (decimal);
}

char	*negation(char *binary)
{
	for (int i = 0; i < 4; i++)
		binary[i] = (binary[i] == '1') ? '0' : '1';
	return (binary);
}

char	*getAnd(char *a, char *b)
{
	a = (a[0] == '~') ? negation(a + 1) : a;
	b = (b[0] == '~') ? negation(b + 1) : b;
	for (int i = 0; i < 4; i++)
		a[i] = (a[i] == '0' || b[i] == '0') ? '0' : a[i];
	return (a);
}

char	*getOr(char *a, char *b)
{
	a = (a[0] == '~') ? negation(a + 1) : a;
	b = (b[0] == '~') ? negation(b + 1) : b;
	for (int i = 0; i < 4; i++)
		a[i] = (a[i] == '1' || b[i] == '1') ? '1' : a[i];
	return (a);
}
