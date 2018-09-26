#include "header.h"

int		carPosition(unsigned int parkingRow)
{
	int		ret;

	ret = -1;
	if (parkingRow != 0 && !(parkingRow & (parkingRow - 1)))
	{
		for (ret = 0; parkingRow > 1; ret += 1)
			parkingRow >>= 1;
	}
	return (ret);
}
