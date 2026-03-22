#include "combinatorics/combinations.hpp"
#include <gtest/gtest.h>

#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <cstdint>


namespace
{
    void sortNested(std::vector<std::vector<int>>& data)
    {
        for (auto& row : data)
        {
            std::sort(row.begin(), row.end());
        }
        std::sort(data.begin(), data.end());
    }
}

TEST(NCkTest, ReturnsOneForKEqualZero)
{
    EXPECT_EQ(nCk(5, 0), 1ULL);
    EXPECT_EQ(nCk(0, 0), 1ULL);
    EXPECT_EQ(nCk(10, 0), 1ULL);
}

TEST(NCkTest, ReturnsOneForKEqualN)
{
    EXPECT_EQ(nCk(1, 1), 1ULL);
    EXPECT_EQ(nCk(5, 5), 1ULL);
    EXPECT_EQ(nCk(10, 10), 1ULL);
}

TEST(NCkTest, HandlesSmallBasicValues)
{
    EXPECT_EQ(nCk(5, 1), 5ULL);
    EXPECT_EQ(nCk(5, 2), 10ULL);
    EXPECT_EQ(nCk(5, 3), 10ULL);
    EXPECT_EQ(nCk(5, 4), 5ULL);
}

TEST(NCkTest, HandlesMediumValues)
{
    EXPECT_EQ(nCk(6, 2), 15ULL);
    EXPECT_EQ(nCk(6, 3), 20ULL);
    EXPECT_EQ(nCk(10, 3), 120ULL);
    EXPECT_EQ(nCk(10, 5), 252ULL);
}

TEST(NCkTest, IsSymmetric)
{
    EXPECT_EQ(nCk(8, 2), nCk(8, 6));
    EXPECT_EQ(nCk(10, 3), nCk(10, 7));
    EXPECT_EQ(nCk(12, 4), nCk(12, 8));
}

TEST(NCkTest, HandlesLargerKnownValues)
{
    EXPECT_EQ(nCk(20, 10), 184756ULL);
    EXPECT_EQ(nCk(30, 15), 155117520ULL);
}

TEST(NCkTest, HandlesSingleElementSelection)
{
    for (int n = 1; n <= 20; ++n)
    {
        EXPECT_EQ(nCk(n, 1), static_cast<u64>(n));
    }
}

// =========================
// Tests for combinations
// =========================

TEST(CombinationsTest, OneElementFromOne)
{
    std::vector<std::vector<int>> expected = {
        {1}
    };

    auto actual = combinations(1, 1);

    sortNested(actual);
    sortNested(expected);

    EXPECT_EQ(actual, expected);
}

TEST(CombinationsTest, ChooseTwoFromFour)
{
    std::vector<std::vector<int>> expected = {
        {1, 2},
        {1, 3},
        {1, 4},
        {2, 3},
        {2, 4},
        {3, 4}
    };

    auto actual = combinations(4, 2);

    sortNested(actual);
    sortNested(expected);

    EXPECT_EQ(actual, expected);
}

TEST(CombinationsTest, ChooseThreeFromFour)
{
    std::vector<std::vector<int>> expected = {
        {1, 2, 3},
        {1, 2, 4},
        {1, 3, 4},
        {2, 3, 4}
    };

    auto actual = combinations(4, 3);

    sortNested(actual);
    sortNested(expected);

    EXPECT_EQ(actual, expected);
}

TEST(CombinationsTest, ChooseAllElements)
{
    std::vector<std::vector<int>> expected = {
        {1, 2, 3, 4}
    };

    auto actual = combinations(4, 4);

    sortNested(actual);
    sortNested(expected);

    EXPECT_EQ(actual, expected);
}

TEST(CombinationsTest, ChooseZeroElements)
{
    std::vector<std::vector<int>> expected = {
        {}
    };

    auto actual = combinations(4, 0);

    sortNested(actual);
    sortNested(expected);

    EXPECT_EQ(actual, expected);
}

TEST(CombinationsTest, ResultCountMatchesNCk)
{
    auto actual = combinations(5, 3);
    EXPECT_EQ(actual.size(), nCk(5, 3));
}

TEST(CombinationsTest, EveryCombinationHasCorrectSize)
{
    auto actual = combinations(5, 3);

    for (const auto& comb : actual)
    {
        EXPECT_EQ(comb.size(), 3u);
    }
}

TEST(CombinationsTest, ElementsAreStrictlyIncreasingInsideEachCombination)
{
    auto actual = combinations(5, 3);

    for (const auto& comb : actual)
    {
        for (size_t i = 1; i < comb.size(); ++i)
        {
            EXPECT_LT(comb[i - 1], comb[i]);
        }
    }
}

TEST(CombinationsTest, ValuesStayWithinRange)
{
    int n = 5;
    auto actual = combinations(n, 3);

    for (const auto& comb : actual)
    {
        for (int value : comb)
        {
            EXPECT_GE(value, 1);
            EXPECT_LE(value, n);
        }
    }
}