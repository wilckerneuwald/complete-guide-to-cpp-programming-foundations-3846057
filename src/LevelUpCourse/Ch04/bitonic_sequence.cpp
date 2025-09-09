// Check if a vector of integers is bitonic

#include <iostream>
#include <vector>

enum States { ASCENDING, DESCENDING, CONSTANT };

bool is_bitonic(const std::vector<int>& sequence) {
    bool bitonic = true;
    int inflections = 0;
    int bottom_inflection = 0;
    States state = States::CONSTANT;

    for (int i = 0; i < sequence.size() - 1; i++) {
        if (sequence[i] < sequence[i + 1] && state != States::ASCENDING) {
            state = States::ASCENDING;
            inflections++;
        } else if (sequence[i] > sequence[i + 1] && state != States::DESCENDING) {
            state = States::DESCENDING;
            inflections++;
        }
    }
    if (state == States::ASCENDING && (sequence.back() > sequence.front())) inflections++;
    if (state == States::DESCENDING && (sequence.back() < sequence.front())) inflections++;
    std::cout << "Number of inflections: " << inflections << std::endl;
    bitonic = inflections <= 3;
    return bitonic;
}

int main() {
    std::vector<int> sequence = {8, 9, 8, 8, 8, 2, 3, 3, 4, 5, 6, 8};
    if (is_bitonic(sequence)) {
        std::cout << "Sequence is bitonic\n";
    } else {
        std::cout << "Sequence is not bitonic\n";
    }

    return 0;
}