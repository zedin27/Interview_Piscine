#include "header.h"
#include <stdlib.h>

int		selectHotspots(struct s_hotspot **hotspots)
{
	int res;
	int covered;

	res = 1;
	covered = 0;
	if (hotspots)
	{
		for (int i = 1; hotspots[i]; i++)
		{
			if (abs(hotspots[i]->pos - hotspots[i]->radius) >= covered)
			{
				covered = hotspots[i]->pos + hotspots[i]->radius;
				res++;
			}
			if (covered > hotspots[i]->pos + hotspots[i]->radius)
				covered = hotspots[i]->pos + hotspots[i]->radius;
		}
	}
	return (res);
}
