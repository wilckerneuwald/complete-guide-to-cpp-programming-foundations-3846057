// Complete Guide to C++ Programming Foundations
// Exercise 07_08
// Operator Overload, by Eduardo Corpeño

#include <iostream>

#include "inventory.h"

int main() {
    // Create an inventory with capacity of 5 items
    Inventory myInventory(5);

    // Add 5 items
    myInventory += "Health Potion";
    myInventory += "Mana Potion";
    myInventory += "Sword";
    myInventory += "Shield";
    myInventory += "Bow";

    // Display current inventory
    myInventory.displayInventory();

    // Try to add another item when inventory is full
    myInventory += "Arrow";

    // Remove an item
    myInventory -= "Mana Potion";

    // Display the item count
    std::cout << "The inventory now contains: " << myInventory.getItemCount() << " items."
              << std::endl;

    // Access item by index
    std::cout << "Item at index 2: " << myInventory[2] << std::endl;

    // Display final state of inventory
    myInventory.displayInventory();

    std::cout << std::endl << std::endl;
    return 0;
}
