#include "header.h"
#include <stdlib.h>
#include <string.h>
//Implement circular doubly linked list

t_node	*init(char c)
{
	t_node *node;

	node = malloc(sizeof(t_node));
	node->next = NULL;
	node->prev = NULL;
	node->c = c;
	return (node);
}

void	insert_after(t_node **list, t_node *new_node)
{
	t_node *head;

	if (*list == NULL)
		*list = new_node;
	else
	{
		for (head = *list; head->next; head = head->next)
			 ;
		head->next = new_node;
		head->next->prev = head;
	}
}

void print_list(t_node *list)
{
	t_node *head;

	head = list;
	while (list)
	{
		list = list->next;
		if (head == list)
			break ;
	}
}

char		*precious(int *text, int size)
{
	int		i;
	char	*res;
	t_node	*head, *tail;

	i = 1;
	res = malloc(sizeof(char) + (size + 1));
	head = init(CS[0]);
	for (i = 1; (size_t)i < strlen(CS); i++)
			insert_after(&head, init(CS[i]));
	for (tail = head; tail->next; tail = tail->next)
		;
	head->prev = tail;
	tail->next = head;
	i = 0;
	while (i < size)
	{
		if (text[i] > 0)
		{
			while (text[i]-- > 0)
				head = head->next;
			res[i] = head->c;
		}
		else
		{
			while (text[i]++ < 0)
				head = head->prev;
			res[i] = head->c;
		}
		i++;
	}
	return (res);
}
