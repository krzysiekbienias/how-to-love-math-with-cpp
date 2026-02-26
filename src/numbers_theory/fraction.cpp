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

Fraction::Fraction(i64 num, i64 den) : m_num(num), m_den(den) {
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

Fraction Fraction::operator*(const Fraction& other) const {
    if (m_den == 0 || other.m_den == 0) {
        throw std::invalid_argument("Fraction::operator*: denominator is zero");
    }

    if (m_num == 0 || other.m_num == 0) {
        return Fraction(0, 1);
    }

    i64 a = m_num;
    i64 b = m_den;
    i64 c = other.m_num;
    i64 d = other.m_den;

    // Cross-cancel a with d
    {
        i64 g1 = gcdIterativeEuclides(std::abs(a), std::abs(d));
        a /= g1;
        d /= g1;
    }

    // Cross-cancel c with b
    {
        i64 g2 = gcdIterativeEuclides(std::abs(c), std::abs(b));
        c /= g2;
        b /= g2;
    }

    // Multiply reduced pieces
    // (Still can overflow i64 in extreme cases, but much less likely.)
    i64 num = a * c;
    i64 den = b * d;

    if (den == 0) {
        throw std::overflow_error("Fraction::operator*: overflow produced denominator 0");
    }

    // Normalize sign (keep denominator positive)
    if (den < 0) {
        den = -den;
        num = -num;
    }

    Fraction out(num, den);
    return out.reduceFraction();
}