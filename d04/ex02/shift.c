#include "header.h"
#include <string.h>
#include <stdio.h>
# define FLIP(c) ((c == '0') ? '1' : '0')

char	*one_twos_complement(char *binary)
{

	for (int i = 5; i >= 0; i--)
	{
		binary[i] = FLIP(binary[i]);
		if (binary[i] - '0' == 0)
			binary[i] = '1';
		else
			binary[i] = '0';
	}
	return (binary);
}

char		*rightShift(char *bin, int k)
{
	int		len;

	len = strlen(bin);
	for (int i = 0; i < k; i++)
		for (int j = len - 1; j > 0; j--)
			bin[j] = bin[j - 1];
	return (bin);
}

char		*leftShift(char *bin, int k)
{
	char	*cur;

	for (int i = 0; i < k; i++)
	{
		cur = bin + 1;
		while (*cur && *(cur + 1))
		{
			*cur = *(cur + 1);
			cur++;
		}
		*cur = '0';
	}
	return (bin);
}

int			toInt(char *bits)
{
	int		ret;
	int		sign;
	char	*tmp;

	ret = 0;
	sign = 1;
	tmp = strdup(bits);
	if (*tmp == '1')
	{
		sign = -1;
		tmp = one_twos_complement(tmp);
	}
	while (*tmp)
	{
		ret = ret * 2 + *tmp - '0';
		tmp += 1;
	}
	return (ret * sign);
}
