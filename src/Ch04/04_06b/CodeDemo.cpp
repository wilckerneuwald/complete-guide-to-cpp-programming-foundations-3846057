// Complete Guide to C++ Programming Foundations
// Exercise 04_06
// The Vector Class, by Eduardo Corpeño

#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> checkpoints = {
        "Start", "Forest", "Castle"};  // insert at the back-end -> memory contigously

    checkpoints.push_back("Cave");
    checkpoints.push_back("Finish");

    std::cout << checkpoints.size() << std::endl;
    checkpoints[2] = "Dark Castle";
    std::cout << checkpoints[2] << std::endl;

    std::cout << std::endl << std::endl;
    return 0;
}
