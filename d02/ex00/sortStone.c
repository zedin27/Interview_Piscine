#include "header.h"
#include <stdlib.h>
#include <stdio.h>

void	swap(t_stone *a, t_stone *b)
{
	int tmp;

	tmp = (*a)->size;
	(*a)->size = (*b)->size;
	(*b)->size = tmp;
}

void	bubble_sort(t_stone **stone, int size)
{
	int i, j;
	for (i = 0; i < size; i++)
		for (j = 0; j < size-i-1; j++)
			if (((stone[j])->size) < ((stone[j+1])->size))
				swap(stone[j], stone[j+1]);
}

int		arr_len(t_stone **stone)
{
	while (i <)
	return (i);
}

void	bucket_sort(int arr[], int size)
{

}

//Bucket implementation

void	print_list(t_stone **stone, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", (*stone)->size);
	printf("\n");
}

void sortStones(struct s_stone **stone)
{

}
