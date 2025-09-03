// Complete Guide to C++ Programming Foundations
// Exercise 01_02
// Hello World, by Eduardo Corpeño 

#include <iostream>

int main(int argc, char* argv[]){
    std::cout << "Hello World!" << std::endl;

    for (int i=0; i < argc; i++) {
        std::cout << "argv[" << i << "] = " << argv[i] << std::endl;
    }

    std::cout << std::endl;
    return 0;
}