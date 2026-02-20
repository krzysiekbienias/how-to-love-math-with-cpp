#include <gtest/gtest.h>
#include <vector>

int determinant3x3(const std::vector<std::vector<int>>& matrix);

TEST(Determinant3x3, IdentityIsOne) {
    std::vector<std::vector<int>> m{
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
    EXPECT_EQ(determinant3x3(m), 1);
}

TEST(Determinant3x3, DiagonalProduct) {
    std::vector<std::vector<int>> m{
        {2, 0, 0},
        {0, -3, 0},
        {0, 0, 4}
    };
    // det = 2 * (-3) * 4 = -24
    EXPECT_EQ(determinant3x3(m), -24);
}

TEST(Determinant3x3, UpperTriangularProduct) {
    std::vector<std::vector<int>> m{
        {5,  7,  9},
        {0, -2,  3},
        {0,  0,  4}
    };
    // triangular det = product of diagonal
    EXPECT_EQ(determinant3x3(m), 5 * (-2) * 4);
}

TEST(Determinant3x3, ZeroRowGivesZero) {
    std::vector<std::vector<int>> m{
        {1, 2, 3},
        {0, 0, 0},
        {7, 8, 9}
    };
    EXPECT_EQ(determinant3x3(m), 0);
}

TEST(Determinant3x3, DuplicateRowsGivesZero) {
    std::vector<std::vector<int>> m{
        {4, 1, -2},
        {4, 1, -2},
        {0, 3,  5}
    };
    EXPECT_EQ(determinant3x3(m), 0);
}

TEST(Determinant3x3, LinearDependenceGivesZero) {
    // Row3 = Row1 + Row2 => det = 0
    std::vector<std::vector<int>> m{
        { 1,  2,  3},
        { 4, -1,  2},
        { 5,  1,  5}
    };
    EXPECT_EQ(determinant3x3(m), 0);
}

TEST(Determinant3x3, KnownExampleNonZero) {
    // Classic example
    // | 1 2 3 |
    // | 0 1 4 |  det = 1*(1*1-4*6) - 2*(0*1-4*5) + 3*(0*6-1*5) = 1*(-23) -2*(-20) +3*(-5) = 2
    // | 5 6 0 |
    std::vector<std::vector<int>> m{
        {1, 2, 3},
        {0, 1, 4},
        {5, 6, 0}
    };
    EXPECT_EQ(determinant3x3(m), 1);
}

TEST(Determinant3x3, RowSwapFlipsSign) {
    std::vector<std::vector<int>> a{
        {1, 2, 3},
        {0, 1, 4},
        {5, 6, 0}
    };
    std::vector<std::vector<int>> b{
        {0, 1, 4},
        {1, 2, 3}, // swapped first two rows
        {5, 6, 0}
    };
    EXPECT_EQ(determinant3x3(a), 1);
    EXPECT_EQ(determinant3x3(b), -1);
}

TEST(Determinant3x3, NegatingOneRowNegatesDeterminant) {
    std::vector<std::vector<int>> a{
        {2, 1, 0},
        {3, 4, 5},
        {1, 0, 1}
    };
    std::vector<std::vector<int>> b = a;
    for (int j = 0; j < 3; ++j) b[1][j] = -b[1][j]; // negate row 2

    EXPECT_EQ(determinant3x3(b), -determinant3x3(a));
}

TEST(Determinant3x3, LargerButSafeIntegers) {
    // diagonal-ish, still easy to verify
    std::vector<std::vector<int>> m{
        {1000, 0,    0},
        {0,    200,  0},
        {0,    0,   -30}
    };
    EXPECT_EQ(determinant3x3(m), 1000 * 200 * (-30)); // -6,000,000
}