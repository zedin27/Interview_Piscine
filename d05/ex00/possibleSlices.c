#include "header.h"

void	get_sizes(t_array *arr, int pizzaSize)
{
	t_array *arr2;

	if (pizzaSize == 0)
		arrayPrint(arr);
	for (int i = 0; i < pizzaSize; i++)
	{
		arr2 = arrayClone(arr);
		arrayAppend(arr2, pizzaSize - i);
		get_sizes(arr2, i);
	}
}

void	printPossibleSlices(int pizzaSize)
{
	t_array *box = arrayInit();
	get_sizes(box, pizzaSize);
}
