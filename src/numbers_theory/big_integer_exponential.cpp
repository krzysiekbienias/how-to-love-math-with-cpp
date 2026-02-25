#include <string>
#include <vector>
#include "constants.hpp"
#include "numbers_theory/big_integer_exponential.hpp"

#include "numbers_theory/binary_exponential.hpp"

int modularReduction(const std::string& a, int mod)
{
    long long r = 0;
    for (char x : a)

    {
        int nb=x-'0';
        r=(r*10+nb)%mod;
    }
    return r;
}

int bigIntegerExponential(const std::string& a,const std::string& b) {
    long long reducedExp=modularReduction(b, constants::MOD-1);
    long long reducedBase=modularReduction(a,constants::MOD);
    long long res=binExponentialWithMod(reducedBase,reducedExp,constants::MOD);
    return (int)res;
}

