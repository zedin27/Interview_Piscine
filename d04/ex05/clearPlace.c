#include "header.h"

unsigned int	clearPlace(unsigned int parkingRow, int pos)
{
	unsigned int newParking;

	newParking = parkingRow & (parkingRow ^ (1 << pos));
	return (newParking);
}
