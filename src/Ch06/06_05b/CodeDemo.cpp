// Complete Guide to C++ Programming Foundations
// Exercise 06_05
// Overloading Functions, by Eduardo Corpeño

#include <iostream>
#include <string>

// Function to get the speed of a player
int getSpeed(int distance, int time) { return distance / time; }

int getSpeed(double time) { return static_cast<int>(100 / time); }

std::string getSpeed(int distance, int time, const std::string& unit) {
    float speed = distance / (float)time;
    return std::to_string(speed) + " " + unit;
}

int main() {
    int speedInt;
    std::string speedStr;

    speedInt = getSpeed(200, 4);
    std::cout << "Speed (int): " << speedInt << std::endl;

    speedInt = getSpeed(3.5);
    std::cout << "Speed (default): " << speedInt << std::endl;

    speedStr = getSpeed(277, 6, "meters per second");
    std::cout << "Speed (string): " << speedStr << std::endl;

    std::cout << std::endl << std::endl;
    return 0;
}
