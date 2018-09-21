# define RANGE 15
#include "header.h"
#include <stdlib.h>
#include <string.h>

void countSort(unsigned char *utensils, int n)
{
	unsigned char *output;
	int count[RANGE + 1] = {0};
	int i = 0;

	output = malloc(n);
	while (i < n)
	{
		count[utensils[i]]++;
		i++;
	}
	for (i = 1; i < 16; i++)
		count[i] += count[i - 1];
	for (i = 0; i < n; i++)
	{
		output[count[utensils[i]] - 1] = utensils[i];
		count[utensils[i]]--;
	}
	for (i = 0; i < n; i++)
		utensils[i] = output[i];
	free(output);
}
