#include "header.h"

unsigned int setPlace(unsigned int parkingRow, int pos)
{
	unsigned int setPlace;

	setPlace = (parkingRow | (1 << pos));
	return (setPlace);
}
