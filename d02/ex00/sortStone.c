#include "header.h"
#include <stdlib.h>
#include <stdio.h>

void	swap(t_stone **a, t_stone **b)
{
	t_stone *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	bubble_sort(t_stone **stone, int size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size - 1; j++)
			if ((stone[i]->size) < (stone[j]->size))
				swap(&stone[i], &stone[j]);
}

int bucket(t_stone *stone, t_stone **arr)
{
	int num = 0;
	int size = 0;

	if (!stone)
		return (0);
	while (stone)
	{
		if (stone->size != size)
		{
			if (arr)
				arr[num] = stone;
			size = stone->size;
			num++;
		}
		stone = stone->next;
	}
	return (num);
}

t_stone *end(t_stone *stone)
{
	while (stone->next && stone->next->size == stone->size)
		stone = stone->next;
	return (stone);
}

t_stone *regroup(t_stone **arr, int size)
{
	t_stone *stone;

	for (int i = 0; i < size; i++)
	{
		stone = end(arr[i]);
		if (i == size - 1)
			stone->next = NULL;
		else
			stone->next = arr[i + 1];
	}
	return (arr[0]);
}

void sortStones(t_stone **stone)
{
	int bucket_size = bucket(*stone, NULL);
	t_stone *arr[bucket_size];

	bucket(*stone, arr);
	bubble_sort(arr, bucket_size);
	*stone = regroup(arr, bucket_size);
}
