#include <vector>
#include <linear_algebra/matrices/operations/multiplication.hpp>

std::vector<std::vector<int> > multiply(const std::vector<std::vector<int> > &A,
                                        const std::vector<std::vector<int> > &B) {
    int mA = 0;
    int mB = 0;
    int nA = 0;
    int nB = 0;
    if (!A.empty() && !B.empty()) {
        mA = A.size();
        mB = B.size();
        nA = A[0].size();
        nB = B[0].size();
    }
    if (nA != mB) {
        throw std::runtime_error("Incompatible matrix dimensions");
    }
    std::vector<std::vector<int> > C(mA, std::vector<int>(nB, 0));
    for (int i = 0; i < mA; ++i) {
        for (int j = 0; j < nB; ++j) {
            for (int k = 0; k < nA; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}


std::vector<std::vector<int> > sparseMatrixMultiplication(const std::vector<std::vector<int> > &A,
                                                          const std::vector<std::vector<int> > &B) {
    int mA = 0;
    int mB = 0;
    int nA = 0;
    int nB = 0;
    if (!A.empty() && !B.empty()) {
        mA = A.size();
        mB = B.size();
        nA = A[0].size();
        nB = B[0].size();
    }
    if (nA != mB) {
        throw std::runtime_error("Incompatible matrix dimensions");
    }
    std::vector<std::vector<int> > C(mA, std::vector<int>(nB, 0));
    for (int i = 0; i < mA; ++i) {
        for (int k = 0; k < nA; ++k) {
            if (A[i][k] == 0) continue;
            for (int j = 0; j < nB; ++j) {
                if (B[k][j] == 0) continue;
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}



