/*
Produce a sequence of factorials from 0! to n! for a given integer n from 0 to 10.
Only calculate each element once.
Do not call the function n times.
*/

#include <iostream>

void get_sequence_factorials(const int n, int* sequence) {
    *sequence = 1;  // Initialize position 0 with 0! = 1
    for (int i = 1; i <= n; i++) {
        *(sequence + i) = *(sequence + i - 1) * i;
    }
}

int main() {
    int n = 10;
    if (n < 0 || n > 10) {
        std::cout << "Argument out of bounds, 'n' must be within 0 and 10...\n";
        return 0;
    }
    int* sequence = new int[n + 1];
    get_sequence_factorials(n, sequence);
    std::cout << "Sequence: [";
    for (int i = 0; i < n; i++) std::cout << *(sequence + i) << ", ";
    std::cout << *(sequence + n) << "]";
    return 0;
}