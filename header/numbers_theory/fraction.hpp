#pragma once

#include <string>
#include <vector>
#include "types.hpp"

class Fraction {
public:
    Fraction(i64 num,i64 den);

    Fraction &reduceFraction();
    //arithmetic operations

    Fraction operator*(const Fraction& other) const;


    // Grant operator<< access to private data for printing
    friend std::ostream& operator<<(std::ostream& os, const Fraction& f);

private:
    i64 m_num;
    i64 m_den;
};

std::ostream& operator<<(std::ostream& os, const Fraction& f);





