#include "gtest/gtest.h"
#include "HexCorner.h"
#include <iostream>
#include <math.h>

namespace
{
	TEST(HexCornerTest, produces_corner)
	{
		Point center;
		int size = 1;

		ASSERT_NE(0, (HexCorner::pointyHexCorner(center, size, 0)).x);
		ASSERT_NE(0, (HexCorner::pointyHexCorner(center, size, 0)).y);
	};
};
