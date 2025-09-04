// Complete Guide to C++ Programming Foundations
// Exercise 02_09
// Structures, by Eduardo Corpeño 

#include <iostream>
#include <string>

enum class character_role {protagonist, antagonist, sidekick, npc};

struct game_character{
    std::string name;
    int level;
    character_role role;
};

int main(){
    game_character buddy;
    buddy.name = "Tony";
    buddy.level = 10;
    buddy.role = character_role::sidekick;
    std::cout << "Buddy role: " << (int) buddy.role << std::endl << std::endl;
    
    std::cout << std::endl << std::endl;
    return 0;
}
