// Complete Guide to C++ Programming Foundations
// Exercise 06_02
// Passing Values to a Function, by Eduardo Corpeño

#include <iostream>

int square_of_arg(int x) { return x * x; }

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Takes arguments by references.
// References are aliases, don't need to be dereferenced.
// Trated as the variables themselves.
// Gives access to variables from outside the scope
void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 9, b;
    b = square_of_arg(a);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    swap(&a, &b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;

    std::cout << std::endl << std::endl;
    return 0;
}
