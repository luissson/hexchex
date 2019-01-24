#include "gtest/gtest.h"
#include "Point.h"

namespace
{
	TEST(PointTest, produces_null_point)
	{
		Point null_point;
		ASSERT_EQ(0, null_point.x);
		ASSERT_EQ(0, null_point.y);
	};

	TEST(PointTest, produces_point)
	{
		Point a_point(1,2);
		ASSERT_EQ(1, a_point.x);
		ASSERT_EQ(2, a_point.y);
	};
};
