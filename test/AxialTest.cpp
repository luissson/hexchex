#include "gtest/gtest.h"
#include "Axial.h"
#include "Point.h"

TEST(AxialTest, Neighbors)
{
    CubePoint point{0, 0, 0};
    std::set<CubePoint> expected {
        {0, -1, 1},
        {0, 1, -1},
        {1, 0, -1},
        {1, -1, 0},
        {-1, 0, 1},
        {-1, 1, 0}
    };
    std::set<CubePoint> neighbors = point.Neighbors();
    EXPECT_EQ(expected, neighbors);
}

TEST(AxialTest, Conversion)
{
    CubePoint point1{-1, 0, 1};
    HexPoint result1{point1};
    HexPoint expected1{-1, 1};
    EXPECT_EQ(expected1, result1);

    HexPoint point2{2, -1};
    CubePoint result2{point2};
    CubePoint expected2{2, -1, -1};
    EXPECT_EQ(expected2, result2);
}

TEST(AxialTest, Errors)
{
    EXPECT_THROW(CubePoint p(1, 1, 1),
                 std::runtime_error);
}
