#include "header.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct s_queue *queueInit(void)
{
	struct s_queue			*node;
	node = (struct s_queue*)malloc(sizeof(struct s_queue));
	node->first = NULL;
	node->last = NULL;
	return (node);
}

void	enqueue(struct s_queue *queue, char *message)
{
	struct s_node			*node;
	node = (struct s_node *)malloc(sizeof(struct s_node));
	node->message = message;
	node->next = NULL;
	if (!queue->last)
	{
		queue->last = node;
		queue->first = node;
	}
	else
	{
		queue->last->next = node;
		queue->last = queue->last->next;
	}
}

char	*dequeue(struct s_queue *queue)
{
	struct s_node *ptr;
	char *info;

	if (queue->first == NULL)
		return (NULL);
	else
	{
		ptr = queue->first;
		info = strdup(queue->first->message);
		queue->first = queue->first->next;
		if (queue->first == NULL)
			queue->last = NULL;
		free(ptr);
	}
	return (info);
}

char	*peek(struct s_queue *queue)
{
	if (queue->first == NULL)
		return (NULL);
	return (queue->first->message);
}

int					isEmpty(struct s_queue *queue)
{
	return (queue->first == NULL);
}
