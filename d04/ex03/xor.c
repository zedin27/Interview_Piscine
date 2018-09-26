#include "header.h"

char *getXor(char *a, char *b)
{
	for (int i = 0; i < 6; i += 1)
	{
		if ((a[i] == '1' && b[i] != '1') || (a[i] != '1' && b[i] == '1'))
			a[i] = '1';
		else
			a[i] = '0';
	}
	return (a);
}

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
