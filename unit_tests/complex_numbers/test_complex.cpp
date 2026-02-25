#include "complex_numbers/complex.hpp"
#include <gtest/gtest.h>
#include "constants.hpp"


static void ExpectComplexNear(const Complex& actual,
                              const Complex& expected,
                              double epsilon = constants::EPSILON) {
    EXPECT_NEAR(actual.real(), expected.real(), epsilon);
    EXPECT_NEAR(actual.imag(), expected.imag(), epsilon);
}

// --- Real part ---

TEST(ComplexNumbers, RealPart_PurelyReal) {
    const Complex c{1.0, 0.0};
    EXPECT_NEAR(c.real(), 1.0, constants::EPSILON);
}

TEST(ComplexNumbers, RealPart_PurelyImaginary) {
    const Complex c{0.0, 1.0};
    EXPECT_NEAR(c.real(), 0.0, constants::EPSILON);
}

TEST(ComplexNumbers, RealPart_RealAndImaginary) {
    const Complex c{1.0, 2.0};
    EXPECT_NEAR(c.real(), 1.0, constants::EPSILON);
}

// --- Imaginary part ---

TEST(ComplexNumbers, ImaginaryPart_PurelyReal) {
    const Complex c{1.0, 0.0};
    EXPECT_NEAR(c.imag(), 0.0, constants::EPSILON);
}

TEST(ComplexNumbers, ImaginaryPart_PurelyImaginary) {
    const Complex c{0.0, 1.0};
    EXPECT_NEAR(c.imag(), 1.0, constants::EPSILON);
}

TEST(ComplexNumbers, ImaginaryPart_RealAndImaginary) {
    const Complex c{1.0, 2.0};
    EXPECT_NEAR(c.imag(), 2.0, constants::EPSILON);
}

// --- Imaginary unit ---

TEST(ComplexNumbers, ImaginaryUnit) {
    const Complex c1{0.0, 1.0};
    const Complex c2{0.0, 1.0};
    ExpectComplexNear(c1 * c2, Complex{-1.0, 0.0}, constants::EPSILON);
}

// --- Arithmetic: Addition ---

TEST(ComplexNumbers, Add_PurelyRealNumbers) {
    const Complex c1{1.0, 0.0};
    const Complex c2{2.0, 0.0};
    ExpectComplexNear(c1 + c2, Complex{3.0, 0.0}, constants::EPSILON);
}

TEST(ComplexNumbers, Add_PurelyImaginaryNumbers) {
    const Complex c1{0.0, 1.0};
    const Complex c2{0.0, 2.0};
    ExpectComplexNear(c1 + c2, Complex{0.0, 3.0}, constants::EPSILON);
}

TEST(ComplexNumbers, Add_RealAndImaginaryNumbers) {
    const Complex c1{1.0, 2.0};
    const Complex c2{3.0, 4.0};
    ExpectComplexNear(c1 + c2, Complex{4.0, 6.0}, constants::EPSILON);
}

// --- Arithmetic: Subtraction ---

TEST(ComplexNumbers, Subtract_PurelyRealNumbers) {
    const Complex c1{1.0, 0.0};
    const Complex c2{2.0, 0.0};
    ExpectComplexNear(c1 - c2, Complex{-1.0, 0.0}, constants::EPSILON);
}

TEST(ComplexNumbers, Subtract_PurelyImaginaryNumbers) {
    const Complex c1{0.0, 1.0};
    const Complex c2{0.0, 2.0};
    ExpectComplexNear(c1 - c2, Complex{0.0, -1.0}, constants::EPSILON);
}

TEST(ComplexNumbers, Subtract_RealAndImaginaryNumbers) {
    const Complex c1{1.0, 2.0};
    const Complex c2{3.0, 4.0};
    ExpectComplexNear(c1 - c2, Complex{-2.0, -2.0}, constants::EPSILON);
}

// --- Arithmetic: Multiplication ---

TEST(ComplexNumbers, Multiply_PurelyRealNumbers) {
    const Complex c1{1.0, 0.0};
    const Complex c2{2.0, 0.0};
    ExpectComplexNear(c1 * c2, Complex{2.0, 0.0}, constants::EPSILON);
}

TEST(ComplexNumbers, Multiply_PurelyImaginaryNumbers) {
    const Complex c1{0.0, 1.0};
    const Complex c2{0.0, 2.0};
    ExpectComplexNear(c1 * c2, Complex{-2.0, 0.0}, constants::EPSILON);
}

TEST(ComplexNumbers, Multiply_RealAndImaginaryNumbers) {
    const Complex c1{1.0, 2.0};
    const Complex c2{3.0, 4.0};
    ExpectComplexNear(c1 * c2, Complex{-5.0, 10.0}, constants::EPSILON);
}

// --- Arithmetic: Division ---

TEST(ComplexNumbers, Divide_PurelyRealNumbers) {
    const Complex c1{1.0, 0.0};
    const Complex c2{2.0, 0.0};
    ExpectComplexNear(c1 / c2, Complex{0.5, 0.0}, constants::EPSILON);
}

TEST(ComplexNumbers, Divide_PurelyImaginaryNumbers) {
    const Complex c1{0.0, 1.0};
    const Complex c2{0.0, 2.0};
    ExpectComplexNear(c1 / c2, Complex{0.5, 0.0}, constants::EPSILON);
}

TEST(ComplexNumbers, Divide_RealAndImaginaryNumbers) {
    const Complex c1{1.0, 2.0};
    const Complex c2{3.0, 4.0};
    ExpectComplexNear(c1 / c2, Complex{0.44, 0.08}, constants::EPSILON);
}

// --- Absolute value ---

TEST(ComplexNumbers, Abs_PositivePurelyReal) {
    const Complex c{5.0, 0.0};
    EXPECT_NEAR(c.abs(), 5.0, constants::EPSILON);
}

TEST(ComplexNumbers, Abs_NegativePurelyReal) {
    const Complex c{-5.0, 0.0};
    EXPECT_NEAR(c.abs(), 5.0, constants::EPSILON);
}

TEST(ComplexNumbers, Abs_PurelyImaginaryPositive) {
    const Complex c{0.0, 5.0};
    EXPECT_NEAR(c.abs(), 5.0, constants::EPSILON);
}

TEST(ComplexNumbers, Abs_PurelyImaginaryNegative) {
    const Complex c{0.0, -5.0};
    EXPECT_NEAR(c.abs(), 5.0, constants::EPSILON);
}

TEST(ComplexNumbers, Abs_RealAndImaginary) {
    const Complex c{3.0, 4.0};
    EXPECT_NEAR(c.abs(), 5.0, constants::EPSILON);
}

// --- Conjugate ---

TEST(ComplexNumbers, Conj_PurelyReal) {
    const Complex c{5.0, 0.0};
    ExpectComplexNear(c.conj(), Complex{5.0, 0.0}, constants::EPSILON);
}

TEST(ComplexNumbers, Conj_PurelyImaginary) {
    const Complex c{0.0, 5.0};
    ExpectComplexNear(c.conj(), Complex{0.0, -5.0}, constants::EPSILON);
}

TEST(ComplexNumbers, Conj_RealAndImaginary) {
    const Complex c{1.0, 1.0};
    ExpectComplexNear(c.conj(), Complex{1.0, -1.0}, constants::EPSILON);
}

// --- Exponential ---

TEST(ComplexNumbers, Exp_EulersIdentity) {
    const Complex c{0.0, constants::Pi};
    ExpectComplexNear(c.exp(), Complex{-1.0, 0.0}, constants::EPSILON);
}

TEST(ComplexNumbers, Exp_Zero) {
    const Complex c{0.0, 0.0};
    ExpectComplexNear(c.exp(), Complex{1.0, 0.0}, constants::EPSILON);
}

TEST(ComplexNumbers, Exp_PurelyReal) {
    const Complex c{1.0, 0.0};
    ExpectComplexNear(c.exp(), Complex{constants::e, 0.0}, constants::EPSILON);
}

// Extra credit

TEST(ComplexNumbers, Exp_RealAndImaginary) {
    const Complex c{std::log(2.0), constants::Pi};
    ExpectComplexNear(c.exp(), Complex{-2.0, 0.0}, constants::EPSILON);
}

TEST(ComplexNumbers, Exp_ResultsInRealAndImaginary) {
    const Complex c{std::log(2.0) / 2.0, constants::Pi / 4.0};
    ExpectComplexNear(c.exp(), Complex{1.0, 1.0}, constants::EPSILON);
}

// --- Operations between real and complex ---

TEST(ComplexNumbers, AddRealToComplex) {
    const Complex c{1.0, 2.0};
    ExpectComplexNear(c + 5.0, Complex{6.0, 2.0}, constants::EPSILON);
}

TEST(ComplexNumbers, AddComplexToReal) {
    const Complex c{1.0, 2.0};
    ExpectComplexNear(5.0 + c, Complex{6.0, 2.0}, constants::EPSILON);
}

TEST(ComplexNumbers, SubtractRealFromComplex) {
    const Complex c{5.0, 7.0};
    ExpectComplexNear(c - 4.0, Complex{1.0, 7.0}, constants::EPSILON);
}

TEST(ComplexNumbers, SubtractComplexFromReal) {
    const Complex c{5.0, 7.0};
    ExpectComplexNear(4.0 - c, Complex{-1.0, -7.0}, constants::EPSILON);
}

TEST(ComplexNumbers, MultiplyComplexByReal) {
    const Complex c{2.0, 5.0};
    ExpectComplexNear(c * 5.0, Complex{10.0, 25.0}, constants::EPSILON);
}

TEST(ComplexNumbers, MultiplyRealByComplex) {
    const Complex c{2.0, 5.0};
    ExpectComplexNear(5.0 * c, Complex{10.0, 25.0}, constants::EPSILON);
}

TEST(ComplexNumbers, DivideComplexByReal) {
    const Complex c{10.0, 100.0};
    ExpectComplexNear(c / 10.0, Complex{1.0, 10.0}, constants::EPSILON);
}

TEST(ComplexNumbers, DivideRealByComplex) {
    const Complex c{1.0, 1.0};
    ExpectComplexNear(5.0 / c, Complex{2.5, -2.5}, constants::EPSILON);
}