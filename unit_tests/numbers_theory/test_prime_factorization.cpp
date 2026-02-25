#include "numbers_theory/prime_factorization.hpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>


using ::testing::ElementsAre;
using ::testing::IsEmpty;
using ::testing::UnorderedElementsAre;
using ::testing::Pair;
using ::testing::IsEmpty;

TEST(PrimeFactors, ReturnsEmptyForNonPositiveAndOne) {
    EXPECT_THAT(primeFactors(-10), IsEmpty());
    EXPECT_THAT(primeFactors(0), IsEmpty());
    EXPECT_THAT(primeFactors(1), IsEmpty());
}

TEST(PrimeFactors, HandlesSmallPrimes) {
    EXPECT_THAT(primeFactors(2), ElementsAre(2));
    EXPECT_THAT(primeFactors(3), ElementsAre(3));
    EXPECT_THAT(primeFactors(97), ElementsAre(97));
}

TEST(PrimeFactors, HandlesPowers) {
    EXPECT_THAT(primeFactors(4),  ElementsAre(2,2));
    EXPECT_THAT(primeFactors(8),  ElementsAre(2,2,2));
    EXPECT_THAT(primeFactors(9),  ElementsAre(3,3));
    EXPECT_THAT(primeFactors(27), ElementsAre(3,3,3));
}

TEST(PrimeFactors, HandlesMixedComposites) {
    EXPECT_THAT(primeFactors(6),  ElementsAre(2,3));
    EXPECT_THAT(primeFactors(12), ElementsAre(2,2,3));
    EXPECT_THAT(primeFactors(18), ElementsAre(2,3,3));
    EXPECT_THAT(primeFactors(84), ElementsAre(2,2,3,7));
}

TEST(PrimeFactors, CapturesLeftoverLargePrimeFactor) {
    EXPECT_THAT(primeFactors(2 * 503), ElementsAre(2,503));
    EXPECT_THAT(primeFactors(45 * 97), ElementsAre(3,3,5,97));
}

TEST(PrimeFactors, HandlesPrimeSquares) {
    EXPECT_THAT(primeFactors(49),  ElementsAre(7,7));
    EXPECT_THAT(primeFactors(121), ElementsAre(11,11));
}


TEST(CountPrimeFactors, ReturnsEmptyForEmptyInput) {
    EXPECT_THAT(countPrimeFactors({}), IsEmpty());
}

TEST(CountPrimeFactors, HandlesSingleFactor) {
    EXPECT_THAT(
        countPrimeFactors({7}),
        UnorderedElementsAre(Pair(7, 1))
    );
}

TEST(CountPrimeFactors, HandlesRepeatedFactors) {
    EXPECT_THAT(
        countPrimeFactors({2,2,2}),
        UnorderedElementsAre(Pair(2, 3))
    );
}

TEST(CountPrimeFactors, HandlesMixedFactors) {
    EXPECT_THAT(
        countPrimeFactors({2,2,3,5,5,5}),
        UnorderedElementsAre(
            Pair(2, 2),
            Pair(3, 1),
            Pair(5, 3)
        )
    );
}

TEST(CountPrimeFactors, HandlesLargePrimeFactor) {
    EXPECT_THAT(
        countPrimeFactors({503,503,7}),
        UnorderedElementsAre(
            Pair(503, 2),
            Pair(7, 1)
        )
    );
}