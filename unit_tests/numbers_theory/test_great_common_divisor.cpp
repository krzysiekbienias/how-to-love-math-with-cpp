#include "numbers_theory/great_common_divisor.hpp"
#include <gtest/gtest.h>
#include <numeric>

// Argument for function: std::vector<int> readInputFileClassic(const std::string& path)
// Use path like: data/hacker_rank_input_for_ut/<file>.txt



// Helper to compare both implementations against each other
static void expect_same(int a, int b, int expected) {
    EXPECT_EQ(gcdRecursive(a, b), expected) << "recursive failed for (" << a << "," << b << ")";
    EXPECT_EQ(gcdIterativeEuclides(a, b), expected) << "iterative failed for (" << a << "," << b << ")";
}

TEST(GcdEuclid, BasicKnownValues) {
    expect_same(48, 18, 6);
    expect_same(54, 24, 6);
    expect_same(17, 13, 1);
    expect_same(100, 10, 10);
    expect_same(270, 192, 6);
}

TEST(GcdEuclid, SameNumbers) {
    expect_same(5, 5, 5);
    expect_same(12345, 12345, 12345);
}

TEST(GcdEuclid, ZeroCases) {
    // With your current implementations:
    // gcd(a,0) returns a
    // gcd(0,b) returns b (for b>0) in iterative; recursive gives b as well via recursion.
    expect_same(0, 0, 0);
    expect_same(0, 7, 7);
    expect_same(7, 0, 7);
}

TEST(GcdEuclid, Symmetry) {
    const int a = 84, b = 30;
    EXPECT_EQ(gcdRecursive(a, b), gcdRecursive(b, a));
    EXPECT_EQ(gcdIterativeEuclides(a, b), gcdIterativeEuclides(b, a));
}

TEST(GcdEuclid, AgreementWithStdGcdForNonNegativeInputs) {
    // std::gcd is well-defined for ints and returns non-negative.
    const int cases[][2] = {
        {0, 0}, {0, 9}, {9, 0},
        {1, 999}, {999, 1},
        {12, 18}, {101, 103},
        {120, 45}, {462, 1071}
    };

    for (auto &c : cases) {
        int a = c[0], b = c[1];
        int expected = std::gcd(a, b);
        EXPECT_EQ(gcdRecursive(a, b), expected) << "recursive mismatch for (" << a << "," << b << ")";
        EXPECT_EQ(gcdIterativeEuclides(a, b), expected) << "iterative mismatch for (" << a << "," << b << ")";
    }
}
