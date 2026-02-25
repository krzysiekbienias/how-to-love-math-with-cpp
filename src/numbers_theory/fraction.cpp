#include "numbers_theory/fraction.hpp"
#include "numbers_theory/great_common_divisor.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>  // std::invalid_argument
#include <cstdlib>    // std::abs

std::ostream& operator<<(std::ostream& os, const Fraction& f) {
    os<<f.m_num<<"/"<<f.m_den;
    return os;
}

Fraction::Fraction(int num, int den) : m_num(num), m_den(den) {
}

Fraction &Fraction::reduceFraction() {
    if (m_den == 0) {
        throw std::invalid_argument("Fraction::reduceFraction(): denominator is zero");
    }
    if (m_num == 0) {
        m_den = 1;
        return *this;
    }
    int gcd = gcdIterativeEuclides(std::abs(m_num), std::abs(m_den));


    m_num /= gcd;
    m_den /= gcd;
    // keep denominator positive
    if (m_den < 0) {
        m_den = -m_den;
        m_num = -m_num;
    }
    return *this;
}
