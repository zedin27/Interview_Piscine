#include "header.h"
#include <stdlib.h>
#include <stdio.h>

void reverse_list(t_node *head)
{
	if (head->next != NULL)
		reverse_list(head->next);
	printf("%s ", head->word);
}

void	printReverse(struct s_node *lst)
{
	reverse_list(lst);
	printf("\n");
}
