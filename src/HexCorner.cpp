#include "HexCorner.h"
#include <math.h>
#include <iostream>

Point HexCorner::pointyHexCorner(Point center, int size, int i)
{
	int degrees = 60*i - 30;
	float radians = M_PI / 180 * degrees;

	return Point(center.x + size * cos(radians), 
				 center.y + size * sin(radians));
}
