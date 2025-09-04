// Complete Guide to C++ Programming Foundations
// Exercise 02_10
// Type Casting, by Eduardo Corpeño 

#include <iostream>
#include <cstdint>

int main(){
    float target_x;
    int32_t sprite_x;
    uint32_t player_x;
    uint32_t player_y;

    target_x = -123.45;
    sprite_x = target_x;
    player_x = sprite_x;
    player_y = target_x;

    std::cout << target_x << std::endl;
    std::cout << sprite_x << std::endl;
    std::cout << player_x << std::endl;
    std::cout << static_cast<int32_t>(player_y) << std::endl;

    std::cout << std::endl << std::endl;
    return 0;
}
