#include "numbers_theory/least_common_multipy.hpp"
#include <gtest/gtest.h>
#include "types.hpp"

// If you already have i64 in a shared header, remove this.
using i64 = std::int64_t;



TEST(LCM, BasicKnownValues) {
    EXPECT_EQ(leastCommonMultiply(6, 8), 24);
    EXPECT_EQ(leastCommonMultiply(21, 6), 42);
    EXPECT_EQ(leastCommonMultiply(12, 18), 36);
}

TEST(LCM, CoprimeNumbers) {
    EXPECT_EQ(leastCommonMultiply(7, 9), 63);
    EXPECT_EQ(leastCommonMultiply(13, 17), 221);
}

TEST(LCM, SameNumbers) {
    EXPECT_EQ(leastCommonMultiply(1, 1), 1);
    EXPECT_EQ(leastCommonMultiply(13, 13), 13);
    EXPECT_EQ(leastCommonMultiply(100, 100), 100);
}

TEST(LCM, OneDividesTheOther) {
    EXPECT_EQ(leastCommonMultiply(12, 3), 12);
    EXPECT_EQ(leastCommonMultiply(3, 12), 12);
    EXPECT_EQ(leastCommonMultiply(20, 5), 20);
    EXPECT_EQ(leastCommonMultiply(5, 20), 20);
}

TEST(LCM, ZeroHandling) {
    EXPECT_EQ(leastCommonMultiply(0, 5), 0);
    EXPECT_EQ(leastCommonMultiply(5, 0), 0);
    EXPECT_EQ(leastCommonMultiply(0, 1), 0);
    EXPECT_EQ(leastCommonMultiply(1, 0), 0);
}

// Property-style test: lcm(a,b) == lcm(b,a)
TEST(LCM, Commutative) {
    const i64 pairs[][2] = {
        {2, 3},
        {6, 8},
        {12, 18},
        {21, 6},
        {100, 25},
        {35, 64},
    };

    for (const auto& p : pairs) {
        const i64 a = p[0];
        const i64 b = p[1];
        EXPECT_EQ(leastCommonMultiply(a, b), leastCommonMultiply(b, a))
            << "Failed for a=" << a << ", b=" << b;
    }
}

TEST(LCM, ZeroZeroReturnsZero) {
    EXPECT_EQ(leastCommonMultiply(0, 0), 0);
}