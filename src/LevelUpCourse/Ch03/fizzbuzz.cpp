/*
    User enters a positive integer n.
    Print a sequence of integers from 1 to n, replacing:
    - Multiples of 3 by "Fizz"
    - Multiples of 5 by "Buzz"
    - Multiples of 3 and 5 by "Buzz"
*/

#include <iostream>
#include <string>

void fizzbuzz(const int n) {
    for (int i = 1; i <= n; i++) {
        if (i % 15 == 0) {
            std::cout << "Fizz Buzz";
        } else if (i % 3 == 0) {
            std::cout << "Fizz";
        } else if (i % 5 == 0) {
            std::cout << "Buzz";
        } else {
            std::cout << i;
        }
        if (i < n)
            std::cout << ", ";
        else
            std::cout << ".";
    }
    std::cout << "\n\n";
}

int main() {
    std::string input;
    int n;

    while (true) {
        std::cout << "Type a positive integer 'n' to play Fizz Buzz. Type '0' to exit: "
                  << std::flush;
        std::cin >> input;

        try {
            n = std::stoi(input);
        } catch (...) {
            std::cout << "Invalid input. Please enter a valid number.\n";
            continue;
        }

        if (n == 0) break;
        if (n < 0) {
            std::cout << "You have to type positive numbers. Try again...\n";
            continue;
        } else {
            fizzbuzz(n);
        }
    }

    return 0;
}