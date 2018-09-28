#include "header.h"
#include <string.h>
#include <stdlib.h>

t_sellers *closestSellers(t_graph *parisPlaces, char *youAreHere)
{
	int count;
	int dist;
	t_node *start;
	t_node *temp;
	t_queue *queue;
	t_queue *bars;
	t_sellers *sellers;

	count = 0;
	dist = 0;
	start = NULL;
	queue = queueInit();
	bars = queueInit();
	sellers = malloc(sizeof(t_sellers));
	sellers->distance = dist;
	sellers->placeNames = malloc(sizeof(char *) * count + 1);
	for (int i = 0; parisPlaces->places[i]; i++)
	{
		if (strcmp(youAreHere, parisPlaces->places[i]->name) == 0)
		{
			start = parisPlaces->places[i];
			break;
		}
	}
	if (!start)
		return (NULL);
	enqueue(queue, start);
	enqueue(queue, NULL);
	while (queue->first)
	{
		while ((temp = dequeue(queue)))
		{
			temp->visited = 1;
			if (temp->hasCerealBar)
			{
				count++;
				enqueue(bars, temp);
			}
			else
			{
				for (int j = 0; temp->connectedPlaces[j]; j++)
					if (temp->connectedPlaces[j]->visited != 1)
					{
						temp->connectedPlaces[j]->visited = 1;
						enqueue(queue, temp->connectedPlaces[j]);
					}
			}
		}
		enqueue(queue, NULL);
		if (count)
			break ;
		dist++;
	}
	for (int i = 0; i < count; i++)
		sellers->placeNames[i] = dequeue(bars)->name;
	sellers->placeNames[count] = NULL;
	return sellers;
}
