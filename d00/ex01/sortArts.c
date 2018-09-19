#include <stdlib.h>
#include <string.h>
#include "header.h"

void    swap(struct s_art **art1, struct s_art **art2)
{
    struct s_art *tmp;

    tmp = *art1;
    *art1 = *art2;
    *art2 = tmp;
}

void    heapify(struct s_art **arts, int n, int i)
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

void    sortArts(struct s_art **arts)
{
    int n = 0;

    for (int i = 0; arts[i] != NULL; i++)
        n++;

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arts, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arts[0], &arts[i]);
        heapify(arts, i, 0);
    }
}
