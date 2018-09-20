#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required
  --------------------------------*/
# define CS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 !?:;,.$&<>()+*-_="

struct s_node {
	char c;
	struct s_node *prev;
	struct s_node *next;
};

/*--------------------------------
  :) function you must implement
  --------------------------------*/
char *precious(int *text, int size);

/*--------------------------------
  ?? test function used in main
  --------------------------------*/


/*--------------------------------
  &  your own other function
  --------------------------------*/

typedef struct s_node t_node;
#endif
// 
//
// #include "header.h"
// #include <stdlib.h>
// #include <string.h>
// #include <stdio.h>
//
// //Implement circular doubly linked list
//
// t_node	*init(char c)
// {
// 	t_node *node;
//
// 	node = malloc(sizeof(t_node));
// 	node->next = NULL;
// 	node->prev = NULL;
// 	node->c = c;
// 	return (node);
// }
//
// void	insert_after(t_node **list, t_node *new_node)
// {
// 	if (*list == NULL)
// 		*list = new_node;
// 	else
// 	{
// 		new_node->next = (*list)->prev->next;
// 		new_node->prev = (*list)->prev;
// 		(*list)->prev->next = new_node;
// 		(*list)->prev = new_node;
// 	}
// }
//
// t_node *iter_list(void)
// {
// 	int i;
// 	int size;
// 	t_node *head;
//
// 	i = -1;
// 	size = strlen(CS);
// 	head = NULL;
// 	while (++i < size)
// 		insert_after(&head, init(CS[i]));
// 	return (head);
// }
//
// void print_list(t_node *list)
// {
// 	t_node *head;
// 	int i;
//
// 	head = list;
// 	i = 0;
// 	while (list)
// 	{
// 		printf("%d ", list->c);
// 		i++;
// 		list = list->next;
// 		if (head == list)
// 			break ;
// 	}
// }
//
// char *precious(int *text, int size)
// {
// 	int temp;
// 	int i;
// 	int j;
// 	int step;
// 	char *letter;
// 	t_node *list;
//
// 	i = -1;
// 	letter = (char*)calloc(size + 1, sizeof(char));
// 	while (++i < size)
// 	{
// 		temp = text[i];
// 		j = temp;
// 		step = temp > 0 ? 1 : -1;
// 		while (j != 0)
// 		{
// 			list = temp > 0 ? list->next : list->prev;
// 			j += step;
// 		}
// 		letter[i] = list->c;
// 	}
// 	return (letter);
// }
