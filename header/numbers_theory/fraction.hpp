#pragma once

#include <string>
#include <vector>

class Fraction {
public:
    Fraction(int num,int den);

    Fraction &reduceFraction();
    // Grant operator<< access to private data for printing
    friend std::ostream& operator<<(std::ostream& os, const Fraction& f);

private:
    int m_num;
    int m_den;
};

std::ostream& operator<<(std::ostream& os, const Fraction& f);





