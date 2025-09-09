// Complete Guide to C++ Programming Foundations
// Exercise 05_04
// While Loops, by Eduardo Corpeño

#include <iostream>
#include <vector>

int main() {
    std::vector<int> playerScores = {12, 25, 31, 47, 58};

    // std::vector<int>::iterator scorePtr = playerScores.begin();
    auto scorePtr = playerScores.begin();

    while (scorePtr != playerScores.end()) {
        std::cout << *scorePtr << " ";
        scorePtr = next(scorePtr, 1);
    }

    int i = 0;
    std::cout << std::endl;
    do {
        std::cout << playerScores[i] << " ";
        i++;
    } while (i < playerScores.size());

    std::cout << std::endl << std::endl;
    return (0);
}
