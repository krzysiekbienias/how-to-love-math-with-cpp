#include "numbers_theory/fraction.hpp"
#include <gtest/gtest.h>

#include <sstream>
#include <stdexcept>



TEST(Fraction_Stream, PrintsRawNumSlashDen) {
    Fraction f(4, 5);
    std::ostringstream oss;
    oss << f;
    EXPECT_EQ(oss.str(), "4/5");
}

TEST(Fraction_Reduce, ReducesSimpleCase) {
    Fraction f(4, 6);
    f.reduceFraction();

    std::ostringstream oss;
    oss << f;
    EXPECT_EQ(oss.str(), "2/3");
}

TEST(Fraction_Reduce, KeepsAlreadyReducedUnchanged) {
    Fraction f(2, 3);
    f.reduceFraction();

    std::ostringstream oss;
    oss << f;
    EXPECT_EQ(oss.str(), "2/3");
}

TEST(Fraction_Reduce, NormalizesNegativeDenominator) {
    Fraction f(1, -2);
    f.reduceFraction();

    std::ostringstream oss;
    oss << f;
    EXPECT_EQ(oss.str(), "-1/2");
}

TEST(Fraction_Reduce, NormalizesBothNegativeToPositive) {
    Fraction f(-2, -4);
    f.reduceFraction();

    std::ostringstream oss;
    oss << f;
    EXPECT_EQ(oss.str(), "1/2");
}

TEST(Fraction_Reduce, NegativeNumeratorStaysNegative) {
    Fraction f(-2, 4);
    f.reduceFraction();

    std::ostringstream oss;
    oss << f;
    EXPECT_EQ(oss.str(), "-1/2");
}

TEST(Fraction_Reduce, ZeroNumeratorBecomesZeroOverOne) {
    Fraction f(0, 7);
    f.reduceFraction();

    std::ostringstream oss;
    oss << f;
    EXPECT_EQ(oss.str(), "0/1");
}

TEST(Fraction_Reduce, ThrowsIfDenominatorZero) {
    Fraction f(3, 0);
    EXPECT_THROW(f.reduceFraction(), std::invalid_argument);
}

TEST(Fraction_Reduce, HandlesZeroNumeratorAndNegativeDenominator) {
    // Your current code hits the m_num==0 early return, so it should become 0/1
    Fraction f(0, -5);
    f.reduceFraction();

    std::ostringstream oss;
    oss << f;
    EXPECT_EQ(oss.str(), "0/1");
}