/*
    Find the probability of having at least two people with same birthday in a group of 'n' randomly
   chosen people.
   Simulate problem 1 milion times with the number of people specified by the user.
   Montecarlo approach. Display the probability of a birthday match.
   Confirm that the probability of match for a group of 23 people is 0.5 (birthday paradox).
*/

#include <iostream>
#include <ostream>
#include <random>
#include <string>
#include <unordered_map>

int main() {
    const int loop = 1000000;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> birthday(1, 366);
    double global_probability = 0.0;
    std::unordered_map<int, int> countMap;
    int group_size = 0;
    std::string input;
    std::cout << "Enter the number of people in the group for the birthday problem simulation: "
              << std::flush;
    std::cin >> input;
    try {
        group_size = std::stoi(input);
    } catch (std::exception) {
        std::cout << "Not possible to cast input to integer. Please restart and provide a valid "
                     "group size..."
                  << std::endl;
        return 1;
    }
    if (group_size < 2) {
        std::cout << "Group size must be bigger or equal to 2. Please restart and provide a valid "
                     "group size..."
                  << std::endl;
        return 1;
    }

    for (int i = 0; i < loop; i++) {
        countMap.clear();
        for (int j = 0; j < group_size; j++) {
            int bd = birthday(gen);
            countMap[bd]++;
            if (countMap[bd] > 1) {
                global_probability += 1.0;
                break;
            }
        }
    }
    global_probability /= loop;

    std::cout << "Probability of at least one colision for group size of '" << group_size
              << "' is approximately: " << global_probability << std::endl;

    return 0;
}