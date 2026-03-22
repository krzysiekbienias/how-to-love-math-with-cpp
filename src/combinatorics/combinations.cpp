#include <string>
#include <vector>
#include <numeric>

using u64= std::uint64_t;

u64 nCk(int n, int k)
{
    u64 res = 1;
    for (int i = 1; i <= k; i++)
    {
        int nom = (n - k + i);
        int denom = i;
        //first reduce
        int gcd1 = std::gcd(nom, denom);
        nom /= gcd1;
        denom /= gcd1;
        //second reduce
        int gcd2 = std::gcd(res, denom);
        res/=gcd2;
        denom /= gcd2;
        //now denom should be equal 1
        res *= nom;
    }
    return res;
}


static void backtrack(int n, int k,int start,std::vector<int>& candidate, std::vector<std::vector<int>>& res) {
    if (candidate.size()==k) {
        res.push_back(candidate);
        return;
    }
    for (int value = start; value <=n; ++value) {
        candidate.push_back(value);
        backtrack(n,k,value+1,candidate,res);
        candidate.pop_back();
    }

}

std::vector<std::vector<int>>combinations(int n,int k) {
    std::vector<std::vector<int>> res;
    std::vector<int> candidate;
    backtrack(n,k,1,candidate,res);
    return res;

}