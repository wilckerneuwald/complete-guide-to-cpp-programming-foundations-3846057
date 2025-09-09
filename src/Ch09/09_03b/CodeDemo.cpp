// Complete Guide to C++ Programming Foundations
// Exercise 09_03
// Opening a Text File for Writing, by Eduardo Corpeño

#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ofstream outFile;
    float a = 4.333f, b = 5.302f;

    outFile.open("calculations.txt", std::ios_base::app);  // Append mode will not overwrite file
    if (outFile.fail())
        std::cout << std::endl << "Couldn't open the file!" << std::endl;
    else {
        outFile << "a = " << a << std::endl;
        outFile << "b = " << b << std::endl;
        outFile << "a + b = " << a + b << std::endl;
        outFile << "a * b = " << a * b << std::endl;
        outFile.close();
        std::cout << "File written successfully!" << std::endl;
    }

    std::cout << std::endl << std::endl;
    return 0;
}
