#include "header.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// int		toInt(char *bits)
// {
// 	int decimal = 0;
// 	int base = 1;
// 	int len = strlen(bits);
//
// 	for (int i = len-1; i >= 0; i--)
// 	{
// 		if (bits[i] == '1')
// 			decimal += base;
// 		base *= 2;
// 	}
// 	return (decimal);
// }
//
// char	*getSum(char *a, char *b)
// {
// 	char sum[6]; //num_a ^ num_b ^ carry
// 	// int num_a;
// 	// int num_b;
// 	int c = 0; //num_a * num_b
//
// 	for (int i = 0; i < 6; i++)
// 	{
// 		printf("Current carry: %d\n", c);
// 		sum[i] = ((a[i] ^ b[i]) ^ c);
// 		printf("Current sum[i]: %c\n", sum[i]);
// 		c = ((a[i] & b[i]) | (a[i] & c)) | (b[i] & c);
// 	}
// 	// while (i >= 0)
// 	// 	printf("%s\n", sum[i--]);
// 	// printf("%s\n", c);
// 	return (strdup(sum));
// }

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

int makeEqualLength(char *str1, char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len1 < len2)
    {
        for (int i = 0 ; i < len2 - len1 ; i++)
            str1 += '0';
        return len2;
    }
    else if (len1 > len2)
    {
        for (int i = 0 ; i < len1 - len2 ; i++)
            str2 += '0';
    }
    return len1; // If len1 >= len2
}

char	*getSum(char *a, char *b)
{
	int len = makeEqualLength(a, b);
	char *res = calloc(6, sizeof(char*)); //num_a ^ num_b ^ carry
	int num_a;
	int num_b;
	int c = 0; //num_a * num_b
	int total = 0;
	
	for (int i = len - 1; i >= 0; i--)
	{
		num_a = toInt(a) - '0';
		num_b = toInt(b) - '0';
		total = (num_a ^ num_b ^ c) + '0';
		res[i] += (char)total;
		c = (num_a & num_b) | (num_b & c) | (num_a & c);
	}
	if (c)
		res += (char)'1';
	return (res);
}

// long binary1, binary2;
//
// int i = 0, remainder = 0, sum[20];
//
//
//
// printf("Enter the first binary number: ");
//
// scanf("%ld", &binary1);
//
// printf("Enter the second binary number: ");
//
// scanf("%ld", &binary2);
//
// while (binary1 != 0 || binary2 != 0)
//
// {
//
// 	sum[i++] =(binary1 % 10 + binary2 % 10 + remainder) % 2;
//
// 	remainder =(binary1 % 10 + binary2 % 10 + remainder) / 2;
//
// 	binary1 = binary1 / 10;
//
// 	binary2 = binary2 / 10;
//
// }
//
// if (remainder != 0)
//   sum[i++] = remainder;
// --i;
// printf("Sum of two binary numbers: ");
//
// while (i >= 0)
// 	printf("%d", sum[i--]);
// return (0);
