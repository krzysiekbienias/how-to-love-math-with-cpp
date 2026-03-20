#include <gtest/gtest.h>
#include <vector>
#include <stdexcept>
#include "linear_algebra/matrices/operations/multiplication.hpp"


TEST(MatrixMultiplyTest, MultipliesOneByOneMatrices) {
    std::vector<std::vector<int>> A = {
        {3}
    };
    std::vector<std::vector<int>> B = {
        {4}
    };

    std::vector<std::vector<int>> expected = {
        {12}
    };

    EXPECT_EQ(multiply(A, B), expected);
}

TEST(MatrixMultiplyTest, MultipliesTwoByTwoMatrices) {
    std::vector<std::vector<int>> A = {
        {1, 2},
        {3, 4}
    };
    std::vector<std::vector<int>> B = {
        {5, 6},
        {7, 8}
    };

    std::vector<std::vector<int>> expected = {
        {19, 22},
        {43, 50}
    };

    EXPECT_EQ(multiply(A, B), expected);
}

TEST(MatrixMultiplyTest, MultipliesRectangularMatrices) {
    std::vector<std::vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6}
    };
    std::vector<std::vector<int>> B = {
        {7, 8},
        {9, 10},
        {11, 12}
    };

    std::vector<std::vector<int>> expected = {
        {58, 64},
        {139, 154}
    };

    EXPECT_EQ(multiply(A, B), expected);
}

TEST(MatrixMultiplyTest, MultipliesFiveByFourAndFourByTwo) {
    std::vector<std::vector<int>> A = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {2, 0, 1, 3},
        {4, 1, 0, 2}
    };

    std::vector<std::vector<int>> B = {
        {1, 2},
        {3, 4},
        {5, 6},
        {7, 8}
    };

    std::vector<std::vector<int>> expected = {
        {50, 60},
        {114, 140},
        {178, 220},
        {28, 34},
        {21, 28}
    };

    EXPECT_EQ(multiply(A, B), expected);
}

TEST(MatrixMultiplyTest, MultipliesRowVectorByColumnVector) {
    std::vector<std::vector<int>> A = {
        {1, 2, 3}
    };
    std::vector<std::vector<int>> B = {
        {4},
        {5},
        {6}
    };

    std::vector<std::vector<int>> expected = {
        {32}
    };

    EXPECT_EQ(multiply(A, B), expected);
}

TEST(MatrixMultiplyTest, MultipliesColumnVectorByRowVector) {
    std::vector<std::vector<int>> A = {
        {1},
        {2},
        {3}
    };
    std::vector<std::vector<int>> B = {
        {4, 5}
    };

    std::vector<std::vector<int>> expected = {
        {4, 5},
        {8, 10},
        {12, 15}
    };

    EXPECT_EQ(multiply(A, B), expected);
}

TEST(MatrixMultiplyTest, HandlesZeroMatrix) {
    std::vector<std::vector<int>> A = {
        {1, 2},
        {3, 4}
    };
    std::vector<std::vector<int>> B = {
        {0, 0},
        {0, 0}
    };

    std::vector<std::vector<int>> expected = {
        {0, 0},
        {0, 0}
    };

    EXPECT_EQ(multiply(A, B), expected);
}

TEST(MatrixMultiplyTest, HandlesNegativeValues) {
    std::vector<std::vector<int>> A = {
        {2, -1},
        {0, 3}
    };
    std::vector<std::vector<int>> B = {
        {4, 5},
        {-2, 1}
    };

    std::vector<std::vector<int>> expected = {
        {10, 9},
        {-6, 3}
    };

    EXPECT_EQ(multiply(A, B), expected);
}

TEST(MatrixMultiplyTest, IdentityMatrixOnRightLeavesMatrixUnchanged) {
    std::vector<std::vector<int>> A = {
        {5, 6},
        {7, 8}
    };
    std::vector<std::vector<int>> I = {
        {1, 0},
        {0, 1}
    };

    std::vector<std::vector<int>> expected = {
        {5, 6},
        {7, 8}
    };

    EXPECT_EQ(multiply(A, I), expected);
}

TEST(MatrixMultiplyTest, IdentityMatrixOnLeftLeavesMatrixUnchanged) {
    std::vector<std::vector<int>> I = {
        {1, 0},
        {0, 1}
    };
    std::vector<std::vector<int>> B = {
        {9, 10},
        {11, 12}
    };

    std::vector<std::vector<int>> expected = {
        {9, 10},
        {11, 12}
    };

    EXPECT_EQ(multiply(I, B), expected);
}

TEST(MatrixMultiplyTest, ThrowsWhenDimensionsAreIncompatible) {
    std::vector<std::vector<int>> A = {
        {1, 2},
        {3, 4}
    };
    std::vector<std::vector<int>> B = {
        {5, 6, 7}
    };

    EXPECT_THROW(multiply(A, B), std::runtime_error);
}