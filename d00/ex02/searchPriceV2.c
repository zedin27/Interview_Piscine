#include "header.h"
#include <string.h>
#include <stdio.h>

int binarySearch(struct s_art **arts, int min, int max, char *name)
{
	int mid;

	while (min <= max)
	{
		mid = min + (max-min) / 2;
		if (!strcmp((arts[mid])->name, name))
			return ((arts[mid])->price);
		if (strcmp((arts[mid])->name, name) < 0)
			min = mid + 1;
		else
			max = mid - 1;
	}
	return (-1);
}

int	searchPrice(struct s_art **arts, int n, char *name)
{
	return (binarySearch(arts, 0, n-1, name));
}
