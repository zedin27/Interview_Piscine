#include "header.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//Backtrack method (what is a memoized?)

void	swap(char *a, char *b)
{
	char tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	permutation(char *str, int start, int end)
{
	if (start == end)
	{
		printf("%s\n", str);
		return ;
	}
	for (int i = 0; i <= end; i++)
	{
		swap(&str[start], &str[i]);
		permutation(str, start + 1, end);
		swap(&str[i], &str[start]);
	}
}

void	printPermutations(char *str)
{
	permutation(str, 0, strlen(str) - 1);
}
