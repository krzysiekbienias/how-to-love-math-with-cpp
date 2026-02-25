#include "numbers_theory/big_integer_exponential.hpp"
#include <gtest/gtest.h>
#include "constants.hpp"


TEST(PowerOfLargeNumbers,ReducingNumber)
{
    int expected=5;
    int actual=modularReduction("3456",7);
    EXPECT_EQ(actual,expected);

}


TEST(PowerOfLargeNumbers, SmallNumbers)

{
    int a1=bigIntegerExponential("4","3");
    int a2=bigIntegerExponential("2","5");
    int a3=bigIntegerExponential("5","2");
    int a4=bigIntegerExponential("5","4");

    EXPECT_EQ(a1,64);
    EXPECT_EQ(a2,32);
    EXPECT_EQ(a3,25);
    EXPECT_EQ(a4,625);


}



TEST(PowerOfLargeNumbers,HugeExponent)
{
    int a1=bigIntegerExponential("1","93475349759384754395743975349573495");
    EXPECT_EQ(a1,1);
};


TEST(PowerOfLargeNumbers,HugeBaseSmallExp)
{
    int a1=bigIntegerExponential("93475349759384754395743975349573495","1");
    int newBase=modularReduction("93475349759384754395743975349573495",constants::MOD);
    EXPECT_EQ(a1,newBase);
};