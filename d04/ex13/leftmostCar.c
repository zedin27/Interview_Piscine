#include "header.h"

int		leftmostCar(unsigned int parkingRow)
{
	int i;

	i = -1
	if (parkingRow != 0)
	{
		for (i = 0; parkingRow != 1; i++)
			parkingRow >>= 1;
	}
	return (i);
}
