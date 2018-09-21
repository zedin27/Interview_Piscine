#include "header.h"
#include <stdlib.h>
#include <stdio.h>

int		size(t_player **players)
{
	int i = 0;

	while (players[i])
		i++;
	return (i);
}

void	divide_conquer(t_player **players, int left, int mid, int right)
{
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;

	t_player *temp_right[n2];
	t_player *temp_left[n1];

	for (i = 0; i < n1; i++)
		temp_left[i] = players[left + i];
	for (j = 0; j < n2; j++)
		temp_right[j] = players[mid + 1 + j];
	i = 0;
	j = 0;
	k = left;
	while (i < n1 &&  j < n2)
	{
		if (temp_left[i]->score > temp_right[j]->score)
		{
			players[k] = temp_left[i];
			i++;
		}
		else
		{
			players[k] = temp_right[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		players[k] = temp_left[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		players[k] = temp_right[j];
		j++;
		k++;
	}
}

void	sort(t_player **players, int left, int right)
{
	int mid = left + (right - left) / 2;

	if (left < right)
	{
		sort(players, left, mid);
		sort(players, mid + 1, right);
		divide_conquer(players, left, mid, right);
	}
}

t_player	**mergeSort(t_player **players)
{
	sort(players, 0, size(players) - 1);
	return (players);
}
