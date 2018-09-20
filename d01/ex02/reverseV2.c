#include "header.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct s_stack *stackInit(void)
{
	struct s_stack *stack;
	stack = (struct s_stack*)malloc(sizeof(struct s_stack));
	if (stack == NULL)
		return (NULL);
	stack->item = NULL;
	return (stack);
}

void *pop(struct s_stack *stack)
{
	struct s_item *elem;
	void *content;

	elem = stack->item;
	if (stack->item == NULL)
		return (NULL);
	content = elem->word;
	stack->item = elem->next;
	free(elem);
	return (content);
}

void push(struct s_stack *stack, char *word)
{
	struct s_item *new;

	if (stack->item == NULL)
	{
		stack->item = (struct s_item*)malloc(sizeof(struct s_item));
		stack->item->word = word;
		stack->item->next = NULL;
	}
	else
	{
		new = (struct s_item*)malloc(sizeof(struct s_item));
		new->word = word;
		new->next = stack->item;
		stack->item = new;
	}
}

void printReverseV2(struct s_node *lst)
{
	struct s_stack *stack;
	int i;

	i = 0;
	stack = stackInit();
	while (lst)
	{
		push(stack, lst->word);
		lst = lst->next;
		i++;
	}
	while (stack->item != NULL)
	{
		if (i == 1)
			printf("%s\n", pop(stack));
		else
			printf("%s ", pop(stack));
		i--;
	}
}
