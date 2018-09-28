#include "header.h"

double	probaDistance(int dist, int *locations, int n)
{
	int res;

	res = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (locations[j] - locations[i] > dist)
			{
				res += n - j;
				break ;
			}
		}
	}
	return ((double)res / (n * (n - 1) / 2));
}
