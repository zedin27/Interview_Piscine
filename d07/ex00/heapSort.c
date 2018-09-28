#include "header.h"
#include <string.h>

void    swap(t_art **art1, t_art **art2)
{
	t_art *tmp;

	tmp = *art1;
	*art1 = *art2;
	*art2 = tmp;
}

void    heapify(t_art **arts, int n, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && strcmp(arts[left]->name, arts[largest]->name) > 0)
		largest = left;
	if (right < n && strcmp(arts[right]->name, arts[largest]->name) > 0)
		largest = right;
	if (largest != i)
	{
		swap(&arts[i], &arts[largest]);
		heapify(arts, n, largest);
	}
}

void    heapSort(t_art **masterpiece, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(masterpiece, n, i);
	for (int i = n - 1; i >= 0; i--)
	{
		swap(&masterpiece[0], &masterpiece[i]);
		heapify(masterpiece, i, 0);
	}
}
