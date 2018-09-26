#include "header.h"

int		occupiedPlaces(unsigned int parkingRow)
{
	for (int i = 0; parkingRow != 0; i++)
		parkingRow &= (parkingRow - 1);
	return (i);
}
