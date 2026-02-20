#include "linear_algebra/matrices/determinant3x3.hpp"

#include <vector>


int determinant3x3(const std::vector<std::vector<int>>& matrix) {
    int a =matrix[0][0];
    int b =matrix[0][1];
    int c =matrix[0][2];
    int d =matrix[1][0];
    int e =matrix[1][1];
    int f =matrix[1][2];
    int g =matrix[2][0];
    int h =matrix[2][1];
    int i =matrix[2][2];

    return a*(e*i-f*h)-b*(d*i-f*g)+c*(d*h-e*g);

}