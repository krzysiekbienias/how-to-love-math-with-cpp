#include <vector>
#include <linear_algebra/matrices/operations/adding.hpp>

std::vector<std::vector<int>> adding(const std::vector<std::vector<int>>&A,const std::vector<std::vector<int>>&B) {
    int mA=0;
    int mB=0;
    int nA=0;
    int nB=0;
    if (!A.empty()&& !B.empty()) {
        mA= A.size();
        mB= B.size();
        nA= A[0].size();
        nB= B[0].size();

    }
    if (mA!=mB || nA!=nB) {
        throw std::runtime_error("Not possible to add");
    }
    std::vector<std::vector<int>> C(mA,std::vector<int> (nB,0));
    for (int i = 0; i < mA; ++i) {
        for (int j = 0; j < nB; ++j) {
            C[i][j]=A[i][j]+B[i][j];

        }

    }


    return C;

}