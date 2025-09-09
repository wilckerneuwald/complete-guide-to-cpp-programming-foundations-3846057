#include "complex.h"

int main() {
    Complex z1 = Complex(10.0, 5.0);
    Complex z2 = Complex(-2.0);

    std::cout << "z1 = ";
    z1.print();

    std::cout << "z2 = ";
    z2.print();

    std::cout << "z1 + z2 = ";
    (z1 + z2).print();

    std::cout << "z1 - z2 = ";
    (z1 - z2).print();

    std::cout << "z1 * z2 = ";
    (z1 * z2).print();

    std::cout << "z1 / z2 = ";
    (z1 / z2).print();

    return 0;
}