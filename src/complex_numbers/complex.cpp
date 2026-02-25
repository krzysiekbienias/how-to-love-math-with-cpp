#include "complex_numbers/complex.hpp"

#include <cmath>
#include <stdexcept>
#include "constants.hpp"




    Complex::Complex(double a, double b) : a(a), b(b) {
    };

    Complex Complex::operator+(const Complex &other) const {
        return {a + other.a, b + other.b};
    }

    Complex Complex::operator+(double x) const {
        return {a + x, b};
    }


    Complex Complex::operator-(const Complex &other) const {
        return {a - other.a, b - other.b};
    }

    Complex Complex::operator-(double x) const {
        return {a - x, b};
    }

    Complex Complex::operator*(const Complex &other) const {
        return {a * other.a - b * other.b, b * other.a + a * other.b};
    }

    Complex Complex::operator*(double x) const {
        return {a * x, b * x};
    }

    Complex Complex::operator/(const Complex &other) const {
        //z1=a+bi
        //z2=c+di
        double c = other.a;
        double d = other.b;

        double denom = c * c + d * d;

        if (denom == 0.0) {
            throw std::domain_error("Complex division by 0+0i.");
        }
        double real = (a * c + b * d) / denom;
        double imag = (b * c - a * d) / denom;

        return {real, imag};
    }

    Complex Complex::operator/(double x) const {
        return {a / x, b / x};
    }

    Complex Complex::conj() const {
        return {a, -b};
    }

    double Complex::modulusSquare() const {
        return a * a + b * b;
    }

    double Complex::abs() const {
        return sqrt(a * a + b * b);
    }

    double Complex::real() const {
        return a;
    }

    double Complex::imag() const {
        return b;
    }

    Complex Complex::exp() const {
        double real = std::pow(constants::e, a) * cos(b);
        double imag = std::pow(constants::e, a) * sin(b);
        return {real, imag};
    }

    //non-member function
    Complex operator+(double x, const Complex &z) {
        return {x + z.a, z.b};
    }

    Complex operator-(double x, const Complex &z) {
        return {x - z.a, -z.b};
    }

    Complex operator*(double x, const Complex &z) {
        return {x * z.a, x * z.b};
    }

    Complex operator/(double x, const Complex &z) {
        double denom = z.a * z.a + z.b * z.b;
        double real = x * z.a / denom;
        double imag = -x * z.b / denom;
        return {real, imag};
    }

