#include <string>
#include <unordered_map>
#include <vector>


std::vector<int> primeFactors(int n) {
    std::vector<int> results;
    if (n<=1) return {};
    //special check for even numbers to decrease the numbers of iterations
    while (n%2==0) {
        results.push_back(2);
        n/=2;
    }
    for (int p=3;p*p<=n;p+=2) {
        while (n%p==0) {
            results.push_back(p);
            n/=p;
        }
    }
    //to capture the last big prime number
    if (n>1) results.push_back(n);
    return results;
}

std::unordered_map<int,int> countPrimeFactors(const std::vector<int> &factors) {
    std::unordered_map<int, int> res;
    for (int x:factors) {
        res[x]++;
    }
    return res;
}

