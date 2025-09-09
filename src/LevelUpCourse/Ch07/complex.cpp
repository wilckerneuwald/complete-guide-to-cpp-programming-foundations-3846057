#include "complex.h"

Complex::Complex(double real_part, double im_part) : real(real_part), im(im_part) {};

Complex Complex::operator+(const Complex& other) const {
    Complex output;
    output.real = real + other.real;
    output.im = im + other.im;
    return output;
};

Complex Complex::operator-(const Complex& other) const {
    Complex output;
    output.real = real - other.real;
    output.im = im - other.im;
    return output;
};

Complex Complex::operator*(const Complex& other) const {
    Complex output;
    output.real = real * other.real - im * other.im;
    output.im = real * other.im + im * other.real;
    return output;
};

Complex Complex::operator/(const Complex& other) const {
    Complex output;
    double denominator = other.real * other.real + other.im * other.im;
    output.real = (real * other.real + im * other.im) / denominator;
    output.im = (im * other.real - real * other.im) / denominator;
    return output;
};

void Complex::print() const {
    if (im < 0)
        std::cout << real << " - " << im * (-1) << "j" << std::endl;
    else
        std::cout << real << " + " << im << "j" << std::endl;
};