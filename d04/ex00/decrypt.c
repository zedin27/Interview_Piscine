#include "header.c"
#include <string.h>
int		bit_to_int(char *bits)
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
	char sum[6]; //num_a ^ num_b ^ carry
	int num_a;
	int num_b;
	int carry = 0; //num_a * num_b
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
