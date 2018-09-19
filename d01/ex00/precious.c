#include "header.h"

//Implement circular doubly linked list

t_node *head = NULL;

t_node	init(char c)
{
	t_node *node;

	node = malloc(sizeof(t_node));
	node->next = NULL;
	node->prev = NULL;
	node->c = c;
	return (node);
}

t_node insert_after(t_node **list, t_node *new_node)
{
	if (*list == NULL)
		*list = new_node;
	else
	{
		new_node->next = (*list)->prev->next;
		new_node->prev = (*list)->prev;
		(*list)->prev->next = new_node;
		(*list)->prev = new_node;
	}
}

t_node iter_list(t_node *list)
{
	int i;
	int size;

	i = -1;
	size = strlen(CS)
	while (++i < size)
		insert_after(&head, init(CS[i]));
	return (head);
}

void printList(t_node *node)
{
	while (node != NULL)
	{
		printf(" %d ", node->data);
		node = node->next;
	}
}

char *precious(int *text, int size)
{

}
