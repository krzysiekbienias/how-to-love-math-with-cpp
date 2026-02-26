#include <string>
#include <vector>
#include "types.hpp"
#include "numbers_theory/great_common_divisor.hpp"

i64 leastCommonMultiply(i64 a ,i64 b) {
    if (a==0 || b==0) {
        return 0;
    }
    i64 g=gcdRecursive(a,b);
    i64 lcm=(a/g)*b;
    return lcm;
}


