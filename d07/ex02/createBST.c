#include "header.h"
#include <stdlib.h>

t_node *createNode(int value)
{
	t_node *node;

	node = (t_node*)malloc(sizeof(t_node));
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

t_node *insertNode(int *arr, int left, int right)
{
	t_node *node;
	int mid;

	mid = left + (right - left) / 2;
	if (left > right)
		return (NULL);
	node = createNode(arr[mid]);
	node->left = insertNode(arr, left, mid - 1);
	node->right = insertNode(arr, mid + 1, right);
	return (node);
}

t_node *createBST(int *arr, int n)
{
	t_node *node;

	node = NULL;
	if (n <= 0)
		return node;
	return insertNode(arr, 0, n - 1);
}
