#include <gtest/gtest.h>
#include <climits>
#include <cstdint>
#include <vector>
#include <tuple>
#include "numbers_theory/binary_exponential.hpp"

// Function under test binExponentialWithMod

namespace {
    // --- Helpers (only for tests) ---
    static long long NormalizeMod(long long x, long long m) {
        // assumes m > 0
        long long r = x % m;
        if (r < 0) r += m;
        return r;
    }

    static long long SlowPowMod_Safe(long long a, long long b, long long m) {
        // Reference implementation for tests using __int128 to avoid overflow.
        // Handles negative a by normalizing into [0, m-1].
        if (m == 1) return 0;
        if (b < 0) return 0; // not defined for negative exponent in integer modular arithmetic; avoid use in tests
        __int128 base = NormalizeMod(a, m);
        __int128 res = 1 % m;
        for (long long i = 0; i < b; ++i) {
            res = (res * base) % m;
        }
        return (long long)res;
    }

    static long long FastRefPowMod(long long a, long long b, long long m) {
        // Another reference: fast pow using __int128.
        if (m == 1) return 0;
        if (b < 0) return 0;
        __int128 base = NormalizeMod(a, m);
        __int128 res = 1 % m;
        long long exp = b;
        while (exp > 0) {
            if (exp & 1LL) res = (res * base) % m;
            base = (base * base) % m;
            exp >>= 1LL;
        }
        return (long long)res;
    }
}
// ------------------- Unit Tests -------------------
TEST(BinExpMod,InterviewBit) {
    EXPECT_EQ(binExponentialWithMod(-1,1,20),19);
    EXPECT_EQ(binExponentialWithMod(0, 0, 1), 1);
    EXPECT_EQ(binExponentialWithMod(71045970, 41535484, 64735492), 20805472);
}


TEST(BinExpMod, ModIsOne_AlwaysZero) {

    EXPECT_EQ(binExponentialWithMod(5, 0, 1), 0);
    EXPECT_EQ(binExponentialWithMod(5, 123456, 1), 0);
    EXPECT_EQ(binExponentialWithMod(-7, 42, 1), 0);
}

TEST(BinExpMod, ExponentZero_ReturnsOneModM) {
    EXPECT_EQ(binExponentialWithMod(0, 0, 2), 1);     // common competitive-programming convention
    EXPECT_EQ(binExponentialWithMod(10, 0, 7), 1);
    EXPECT_EQ(binExponentialWithMod(-10, 0, 7), 1);
    EXPECT_EQ(binExponentialWithMod(123, 0, 97), 1);
}

TEST(BinExpMod, BaseZero) {
    EXPECT_EQ(binExponentialWithMod(0, 1, 5), 0);
    EXPECT_EQ(binExponentialWithMod(0, 2, 5), 0);
    EXPECT_EQ(binExponentialWithMod(0, 999999, 5), 0);
}

TEST(BinExpMod, SmallKnownValues) {
    EXPECT_EQ(binExponentialWithMod(2, 10, 1000), 24); // 1024 % 1000
    EXPECT_EQ(binExponentialWithMod(3, 4, 17), 13);    // 81 % 17 = 13
    EXPECT_EQ(binExponentialWithMod(5, 3, 13), 8);     // 125 % 13 = 8
    EXPECT_EQ(binExponentialWithMod(7, 2, 10), 9);     // 49 % 10 = 9
}

TEST(BinExpMod, BaseEqualsModOrMultipleOfMod) {
    EXPECT_EQ(binExponentialWithMod(10, 1, 10), 0);
    EXPECT_EQ(binExponentialWithMod(10, 2, 10), 0);
    EXPECT_EQ(binExponentialWithMod(20, 123, 10), 0);
    EXPECT_EQ(binExponentialWithMod(-30, 5, 10), 0);
}

TEST(BinExpMod, NegativeBase_NormalizedResultExpected) {
    // These tests enforce the common convention: result is in [0, m-1].
    // If your implementation returns negative residues, these will fail (good signal to normalize).
    EXPECT_EQ(binExponentialWithMod(-2, 1, 5), 3);          // -2 % 5 => 3
    EXPECT_EQ(binExponentialWithMod(-2, 2, 5), 4);          // 4
    EXPECT_EQ(binExponentialWithMod(-3, 3, 7), 1);          // (-3)^3=-27 mod7=1
    EXPECT_EQ(binExponentialWithMod(-10, 5, 13), FastRefPowMod(-10, 5, 13));
}

TEST(BinExpMod, ResultAlwaysInRangeForPositiveMod) {
    // Property test: output should be in [0, m-1] for m>0
    struct Case { long long a,b,m; };
    std::vector<Case> cases = {
        { -123456789LL, 1, 97 },
        { -123456789LL, 2, 97 },
        {  123456789LL, 3, 97 },
        {  2LL, 62, 1000000007LL },
        { -2LL, 63, 1000000007LL },
        { LLONG_MIN + 1, 5, 1000003LL },
        { LLONG_MAX, 5, 1000003LL },
    };
    for (const auto& c : cases) {
        long long out = binExponentialWithMod(c.a, c.b, c.m);
        EXPECT_GE(out, 0) << "a=" << c.a << " b=" << c.b << " m=" << c.m;
        EXPECT_LT(out, c.m) << "a=" << c.a << " b=" << c.b << " m=" << c.m;
    }
}

TEST(BinExpMod, CrossCheckAgainstReference_SmallExponents) {
    // A bunch of mixed cases, but with small b to allow a slow reference too.
    std::vector<std::tuple<long long,long long,long long>> cases = {
        {2, 0, 11},
        {2, 1, 11},
        {2, 2, 11},
        {2, 10, 11},
        {7, 13, 19},
        {12, 8, 17},
        {-12, 8, 17},
        {1234567, 9, 1009},
        {-1234567, 9, 1009},
        {LLONG_MAX, 3, 1000003},
        {LLONG_MIN + 1, 3, 1000003},
    };

    for (auto [a,b,m] : cases) {
        long long got = binExponentialWithMod(a,b,m);
        long long exp = SlowPowMod_Safe(a,b,m);
        EXPECT_EQ(got, exp) << "a=" << a << " b=" << b << " m=" << m;
    }
}

TEST(BinExpMod, CrossCheckAgainstFastReference_LargeExponent) {
    // Ensures you truly use binary exponentiation and handle large b.
    const long long m = 1000000007LL;
    std::vector<std::tuple<long long,long long>> cases = {
        {2, 1000000000000LL},
        {5, 9223372036854775807LL / 2}, // big positive exponent
        {-2, 123456789012345LL},
        {123456789LL, 98765432109876LL},
    };

    for (auto [a,b] : cases) {
        long long got = binExponentialWithMod(a,b,m);
        long long exp = FastRefPowMod(a,b,m);
        EXPECT_EQ(got, exp) << "a=" << a << " b=" << b << " m=" << m;
    }
}

TEST(BinExpMod, FermatLittleTheorem_PrimeMod_Sanity) {
    // For prime p and a not divisible by p: a^(p-1) % p == 1
    const long long p = 1000000007LL;
    std::vector<long long> bases = {2, 3, 5, 123456789LL, p-2, p-5};

    for (long long a : bases) {
        EXPECT_EQ(binExponentialWithMod(a, p-1, p), 1) << "a=" << a;
    }
    // If a is multiple of p => 0^(p-1) = 0 for exponent>0
    EXPECT_EQ(binExponentialWithMod(p, p-1, p), 0);
    EXPECT_EQ(binExponentialWithMod(2*p, p-1, p), 0);
}

TEST(BinExpMod, MultiplicativeProperty_Sanity) {
    // (a^(x+y) mod m) == (a^x mod m) * (a^y mod m) mod m
    const long long m = 1000003LL; // not necessarily prime
    std::vector<std::tuple<long long,long long,long long>> cases = {
        {2, 12345, 67890},
        {-7, 111, 222},
        {123456789, 3333, 4444},
        {m+5, 17, 19},
    };

    for (auto [a,x,y] : cases) {
        long long left  = binExponentialWithMod(a, x+y, m);
        __int128 rhs = (__int128)binExponentialWithMod(a, x, m) * binExponentialWithMod(a, y, m);
        long long right = (long long)(rhs % m);
        EXPECT_EQ(left, right) << "a=" << a << " x=" << x << " y=" << y << " m=" << m;
    }
}

TEST(BinExpMod, HandlesHugeBase_NoOverflowInIntermediate) {
    // These are designed to explode if you multiply in 64-bit without using __int128 / mulmod technique.
    // We validate against a safe reference.
    const long long m = 1000000007LL;

    std::vector<std::tuple<long long,long long>> cases = {
        {LLONG_MAX, 2},
        {LLONG_MAX, 3},
        {LLONG_MIN + 1, 2},
        {LLONG_MIN + 1, 3},
        {9'000'000'000'000'000'000LL, 5},
        {-9'000'000'000'000'000'000LL, 5},
    };

    for (auto [a,b] : cases) {
        long long got = binExponentialWithMod(a,b,m);
        long long exp = FastRefPowMod(a,b,m);
        EXPECT_EQ(got, exp) << "a=" << a << " b=" << b << " m=" << m;
    }
}