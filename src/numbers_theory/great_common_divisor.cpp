#include "types.hpp"

// Implement your logic here.
i64 gcdRecursive(i64 a, i64 b) {
    if (b==0) return a;
    i64 r=a%b;
    return gcdRecursive(b,r);
}


i64 gcdIterativeEuclides(i64 a, i64 b) {
    while (b>0) {
        i64 r=a%b;
        a=b;
        b=r;
    }
    return a;
}


