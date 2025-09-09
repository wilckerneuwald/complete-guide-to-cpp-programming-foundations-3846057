#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <ostream>

class Complex {
   private:
    double real;
    double im;

   public:
    Complex(double real_part = 0.0, double im_part = 0.0);
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;
    void print() const;
};

#endif  // COMPLEX_H