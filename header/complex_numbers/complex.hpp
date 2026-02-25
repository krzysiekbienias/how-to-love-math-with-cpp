#pragma once
#include <string>


class Complex {
public:
    double a;
    double b;

    Complex(double a = 0.0, double b = 0.0);

    Complex operator+(const Complex &other) const;

    Complex operator+(double x) const;

    Complex operator*(const Complex &other) const;

    Complex operator*(double x) const;

    Complex operator-(const Complex &other) const;

    Complex operator-(double x) const;

    Complex operator/(const Complex &other) const;

    Complex operator/(double x) const;

    Complex conj() const;

    double modulusSquare() const;

    double abs() const;

    double real() const;

    double imag() const;

    Complex exp() const;
};

Complex operator+(double x, const Complex &z);

Complex operator-(double x, const Complex &z);

Complex operator*(double x, const Complex &z);

Complex operator/(double x, const Complex &z);
