// Complete Guide to C++ Programming Foundations
// Exercise 04_07
// Using Objects with Vectors, by Eduardo Corpeño

#include <complex>
#include <iostream>
#include <vector>

int main() {
    std::vector<std::complex<double>> points;

    points.push_back(std::complex<double>(3.5, 4.0));
    points.push_back(std::complex<double>(1.5, -4.0));
    points.push_back(std::complex<double>(1.2, 2.0));
    points.push_back(std::complex<double>(-4.4, 2.0));

    std::cout << points.begin()->real() << std::endl;

    std::cout << points[2].real() << std::endl;

    std::cout << (points.end() - 1)->imag() << std::endl;

    std::cout << prev(points.end())->imag() << std::endl;

    std::cout << std::endl << std::endl;
    return 0;
}
