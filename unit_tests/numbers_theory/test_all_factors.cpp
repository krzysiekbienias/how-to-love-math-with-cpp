#include "numbers_theory/all_factors.hpp"
#include <gtest/gtest.h>

#include <gmock/gmock.h>
#include <vector>

using ::testing::ElementsAre;
using ::testing::UnorderedElementsAre;
using ::testing::WhenSorted;
using ::testing::Contains;
using ::testing::Each;
using ::testing::Gt;

//my own matcher
MATCHER(IsSortedAscending, "Checks if container is sorted ascending") {
    return std::is_sorted(arg.begin(), arg.end());
}

TEST(AllFactors, One) {
    EXPECT_THAT(allFactors(1), ElementsAre(1));
}

TEST(AllFactors, PrimeNumber) {
    EXPECT_THAT(allFactors(13), ElementsAre(1, 13));
}

TEST(AllFactors, CompositeNonSquare) {
    EXPECT_THAT(allFactors(12), ElementsAre(1,2,3,4,6,12));
}

TEST(AllFactors, PerfectSquare_NoDuplicateRoot) {
    EXPECT_THAT(allFactors(36),
                ElementsAre(1,2,3,4,6,9,12,18,36));
}

TEST(AllFactors, PrimeSquare) {
    EXPECT_THAT(allFactors(49), ElementsAre(1,7,49));
}

TEST(AllFactors, LargerComposite) {
    EXPECT_THAT(allFactors(84),
                ElementsAre(1,2,3,4,6,7,12,14,21,28,42,84));
}

TEST(AllFactors, ResultIsSortedAscending) {
    EXPECT_THAT(allFactors(48), IsSortedAscending());
}

TEST(AllFactors, ContainsOneAndN) {
    const int n = 90;
    auto result = allFactors(n);

    EXPECT_THAT(result, Contains(1));
    EXPECT_THAT(result, Contains(n));
}

TEST(AllFactors, EveryReturnedValueDividesN) {
    const int n = 120;
    auto result = allFactors(n);

    for (int f : result) {
        EXPECT_EQ(n % f, 0);
    }
}

TEST(AllFactors, AllFactorsArePositive) {
    EXPECT_THAT(allFactors(72), Each(Gt(0)));
}