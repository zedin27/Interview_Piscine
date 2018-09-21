#include "header.h"
#include <stdlib.h>

void	insertionSort(t_player **players)
{
	t_player *tmp;
	int j, i;

	i = 0;
	while (players[++i])
	{
		tmp = players[i];
		j = i;
		while (--j >= 0 && (players[j]->score < tmp->score))
			players[j + 1] = players[j];
		players[j + 1] = tmp;
	}
}
