#include "header.h"
#include <string.h>
#include <stdlib.h>

t_deque		*dequeInit(void)
{
	t_deque *queue;

	queue = (t_deque*)malloc(sizeof(t_queue));
	queue->first = NULL;
	queue->last = NULL;
	return (node);
}

// int		isFull(t_deque *deque)
// {
// 	return (deque->value)
// }
//
// int		isEmpty(t_deque *deque)
// {
//	return (deque->value)
// }

void	pushFront(struct s_deque *deque, int value)
{
	t_dequeNode *node;

	node = (t_dequeNode*)malloc(sizeof(t_dequeNode));
	node->value = value;
	if (node == NULL)
		return (NULL);
	if (!deque->first)
	{
		node->next = NULL;
		node->prev = NULL;
		deque->first = node;
		deque->last = node;
	}
	else
	{
		node->next = deque->first;
		node->prev = NULL;
		deque->last->next = node;
		deque->last = deque->last->next;
	}
}
void	pushBack(struct s_deque *deque, int value)
{
	t_dequeNode *node;

	node = (t_dequeNode*)malloc(sizeof(t_dequeNode));
	node->value = value;
	if (node == NULL)
		return (NULL);
	if (!deque->last)
	{
		node->prev = NULL;
		node->next = NULL;
		deque->last = node;
		deque->first = node;
	}
	else
	{

	}
}
int		popFront(struct s_deque *deque)
{

}
int		popBack(struct s_deque *deque)
{

}

int		peekFront(t_deque *deque)
{
	if (!deque)
		return (INT_MIN);
	if (!deque->last)
		return (INT_MIN);
	return (deque->last->value);
}

int		peekRear(t_deque *deque)
{
	if (!deque)
		return (INT_MIN);
	if (!deque->first)
		return (INT_MIN);
	return (deque->first->value);
}

t_max	*maxSW(int *arr, int n, int k)
{

}
