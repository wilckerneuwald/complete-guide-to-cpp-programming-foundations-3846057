// Complete Guide to C++ Programming Foundations
// Exercise 03_05
// Compound Assignment Operators, by Eduardo Corpeño 

#include <iostream>

int main(){
    int ammo = 30;
    int incoming_zombies = 20;

    std::cout << "Initial Ammo: " << ammo << std::endl;
    std::cout << "Initial Zombies Incoming: " << incoming_zombies << std::endl;

    // Addition assignment
    ammo += 10;
    std::cout << ammo << std::endl;

    // Subtraction assignment
    ammo -= 5;
    std::cout << ammo << std::endl;

    // Multiplication assignment
    ammo *= 2;
    std::cout << ammo << std::endl;

    // Division assignment
    ammo /= 2;
    std::cout << ammo << std::endl;

    // Remainder assignment
    ammo %= 6;
    std::cout << ammo << std::endl;

    std::cout << std::endl << std::endl;
    return 0;
}
