#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

void to_lower_case(std::string& phrase) {
    std::transform(phrase.begin(), phrase.end(), phrase.begin(), tolower);
}

// Check if a phrase is a palindrome, that means, is writen the same way backwards.

int main() {
    bool loop = true;
    while (loop) {
        std::string new_phrase, reverse;
        std::cout << "Type a word or phrase to check if it is a palindrome. Type 'Q' to exit: "
                  << std::flush;
        std::getline(std::cin, new_phrase);
        to_lower_case(new_phrase);
        if (new_phrase == "q") break;
        reverse = std::string(new_phrase.rbegin(), new_phrase.rend());
        if (new_phrase == reverse)
            std::cout << "Your phrase is a palindrome: " << reverse << std::endl << std::endl;
        else
            std::cout << "Your phrase is not a palidrome. See reverse: " << reverse << std::endl
                      << std::endl;
    }
    return 0;
}