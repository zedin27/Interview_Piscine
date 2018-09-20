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

int pop(struct s_stack *stack)
{
	struct s_item *elem;
	int content;

	elem = stack->item;
	if (stack->item == NULL)
		return (ERR);
	content = elem->idx;
	stack->item = elem->next;
	free(elem);
	return (content);
}

void push(struct s_stack *stack, int idx)
{
	struct s_item *new;

	if (stack->item == NULL)
	{
		stack->item = (struct s_item*)malloc(sizeof(struct s_item));
		stack->item->idx = idx;
		stack->item->next = NULL;
	}
	else
	{
		new = (struct s_item*)malloc(sizeof(struct s_item));
		new->idx= idx;
		new->next = stack->item;
		stack->item = new;
	}
}

void	free_stack(struct s_stack **stack)
{
	struct s_item *ptr;
	struct s_item *mover;

	ptr = (*stack)->item;
	while (ptr != NULL)
	{
		mover = ptr;
		ptr = ptr->next;
		free(mover);
	}
	free(*stack);
}

// void printReverseV2(struct s_node *lst)
// {
// 	struct s_stack *stack;
// 	int i;
//
// 	i = 0;
// 	stack = stackInit();
// 	while (lst)
// 	{
// 		push(stack, lst->word);
// 		lst = lst->next;
// 		i++;
// 	}
// 	while (stack->item != NULL)
// 	{
// 		if (i == 1)
// 			printf("%s\n", pop(stack));
// 		else
// 			printf("%s ", pop(stack));
// 		i--;
// 	}
// }

char		*console(void)
{
	int		i = 0;
	int		read;
	size_t	len = 0;
	char	*msg = malloc(sizeof(char) + 256);
	char	*buff = NULL;
	struct s_stack	*st = stackInit();

	while (1)
	{
		printf("?: ");
		read = getline(&buff, &len, stdin);
		buff[--read] = '\0';
		if (strcmp(buff, "UNDO") == 0) {
			i = pop(st);
			memset(msg + i, 0, 256 - i);
		}
		else if (strcmp(buff, "SEND") == 0)
		{
			free_stack(&st);
			break ;
		} else if (i + read < 256)
		{
			push(st, i);
			if (i > 0)
			{
				strcat(msg, " ");
				i++;
			}
			strcat(msg, buff);
			i += strlen(buff);
		}
		printf("%s\n\n", msg);
	}
	free(buff);
	buff = NULL;
	return (msg);
}
