#include "header.h"
#include <stdlib.h>

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

char	*getSum(char *a, char *b)
{
	char *res = calloc(7, sizeof(*res));
	int num_a;
	int num_b;
	int c = 0;

	for (int i = 5; i >= 0; i--)
	{
		num_a = (a[i] == '1') ? 1 : 0;
		num_b = (b[i] == '1') ? 1 : 0;
		c += num_a + num_b;
		res[i] += (c % 2) + '0';
		c /= 2;
	}
	return (res);
}
