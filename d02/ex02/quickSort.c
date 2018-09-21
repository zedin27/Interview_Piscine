#include "header.h"

int		size(t_player **players)
{
	int i = 0;

	while (players[i])
		i++;
	return (i);
}

void	swap(t_player **a, t_player **b)
{
	t_player *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(t_player **players, int lo, int hi)
{
	int pivot = players[hi]->score;
	int i = lo;

	for (int j = lo; j < hi; j++)
	{
		if (players[j]->score <= pivot)
		{
			swap(&players[i], &players[j]);
			i++;
		}
	}
	swap(&players[i], &players[hi]);
	return (i);
}

void	pre_quickSort(t_player **players, int lo, int hi)
{
	if (lo < hi)
	{
		int pivot = partition(players, lo, hi);
		pre_quickSort(players, lo, pivot - 1);
		pre_quickSort(players, pivot + 1, hi);
	}
}

void	quickSort(t_player **players)
{
	pre_quickSort(players, 0, size(players) - 1);
}
