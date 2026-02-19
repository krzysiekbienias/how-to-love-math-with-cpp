#pragma once
#include <string>



class Complex
{
public:
    int a;
    int b;
    Complex(int a=0,int b=0);

    void input(std::string s);

    Complex operator+(const Complex& other) const;
    Complex conjugate() const;
    double modulus() const;


};

std::ostream& operator<<(std::ostream& os, const Complex& c);