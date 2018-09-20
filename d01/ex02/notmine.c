struct s_stack	*stackInit(void)
{
	struct s_stack *stack;

	if ((stack = malloc(sizeof(struct s_stack))) == NULL)
		return (NULL);
	stack->item = NULL;
	return (stack);
}

void	*pop(struct s_stack *stack)
{
	struct s_item *ptr;
	char *item;

	ptr = stack->item;
	if (ptr == NULL)
		return (NULL);
	else
	{
		item = ptr->word;
		stack->item = ptr->next;
		free(ptr);
	}
	return (item);
}

void	push(struct s_stack *stack, char *word)
{
	struct s_item *ptr;
	struct s_item *new;

	ptr = stack->item;
	if (ptr == NULL)
	{
		stack->item = malloc(sizeof(struct s_item));
		stack->item->word = word;
		stack->item->next = NULL;
	}
	else
	{
		new = malloc(sizeof(struct s_item));
		new->word = word;
		new->next = ptr;
		stack->item = new;
	}
}

void	printReverseV2(struct s_node *lst)
{
	struct s_stack *stack;
	int i = 0;

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
