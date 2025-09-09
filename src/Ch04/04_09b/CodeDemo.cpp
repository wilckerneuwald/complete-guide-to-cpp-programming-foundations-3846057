// Complete Guide to C++ Programming Foundations
// Exercise 04_09
// C Strings, by Eduardo Corpeño

#include <cstring>
#include <iostream>

int main() {
    const size_t LENGTH = 50;
    char racer1[] = "Speedy";
    char racer2[LENGTH];
    char raceResult[LENGTH * 2];

    strncpy_s(racer2, "Lightning", sizeof(racer2) - 1);
    racer2[sizeof(racer2) - 1] = '\0';

    for (size_t i = 0; i < LENGTH; ++i) {
        std::cout << "racer2[" << i << "] = '" << racer2[i] << "'" << std::endl;
    }

    strncpy_s(raceResult, "And the winner is ", sizeof(raceResult) - 1);
    raceResult[sizeof(raceResult) - 1] = '\0';

    strncat_s(raceResult, racer1, sizeof(raceResult) - strlen(raceResult) - 1);

    std::cout << "Racer 1: " << racer1 << std::endl;
    std::cout << "Racer 2: " << racer2 << std::endl;

    std::cout << raceResult << std::endl;

    std::cout << std::endl << std::endl;
    return 0;
}
