#include "header.h"
#include <string.h>
#include <stdlib.h>
#include <limits.h>

t_deque		*dequeInit(void)
{
	t_deque *queue = malloc(sizeof(t_deque));

	// queue = (t_deque*)malloc(sizeof(t_queue));
	queue->first = NULL;
	queue->last = NULL;
	return (queue);
}

void	pushFront(struct s_deque *deque, int value)
{
	t_dequeNode *node;

	node = (t_dequeNode*)malloc(sizeof(t_dequeNode));
	node->value = value;
	if (!node)
		return ;
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
	if (!node)
		return ;
	if (!deque->last)
	{
		node->prev = NULL;
		node->next = NULL;
		deque->last = node;
		deque->first = node;
	}
	else
	{
		node->next = NULL;
		node->prev = deque->last;
		deque->last->next = node;
		deque->last = node;
	}
}
int	popFront(t_deque *deque)
{
	t_dequeNode *tmp;
	int value;

	if (!deque)
		return INT_MIN;
	if (!deque->first)
		return INT_MIN;
	value = deque->first->value;
	tmp = deque->first;
	deque->first = deque->first->next;

	if (!deque->first)
		deque->last = NULL;
	else
		deque->first->prev = NULL;
	free(tmp);
	return value;
}

int popBack(t_deque *deque)
{
	t_dequeNode *tmp;
	int value;

	if (!deque)
		return INT_MIN;
	if (!deque->last)
		return INT_MIN;
	value = deque->last->value;
	tmp = deque->last;
	deque->last = deque->last->prev;
	if (!deque->last)
		deque->first = NULL;
	else
		deque->last->next = NULL;
	free(tmp);
	return value;
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

t_max	*maxSlidingWindow(int *arr, int n, int k)
{
	t_deque *queue;
	t_max *res;
	int i;

	queue = dequeInit();
	res = (t_max*)malloc(sizeof(t_max));
	res->max = (int*)malloc(sizeof(int)* (n - k + 1));
	res->length = n - k + 1;
	if (k > n || k < 0)
		return (NULL);
	for (i = 0; i < k; i++)
	{
		while (queue->last && peekFront(queue) != INT_MIN && arr[i] >= arr[peekFront(queue)])
			popBack(queue);
		pushBack(queue, i);
	}
	for (i = k; i < n; i++)
	{
		res->max[i - k] = arr[peekFront(queue)];
		while (queue->first && peekRear(queue) != INT_MIN && peekRear(queue) <= i - k)
			popFront(queue);
		while (queue->last && peekFront(queue) != INT_MIN && arr[i] >= arr[peekFront(queue)])
			popBack(queue);
		pushBack(queue, i);
	}
	res->max[i - k] = arr[peekRear(queue)];
	return (res);
}
