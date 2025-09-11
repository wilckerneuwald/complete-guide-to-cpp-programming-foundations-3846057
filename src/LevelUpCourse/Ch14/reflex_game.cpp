/*
    Waits a random delay between four and ten seconds and asks the user to type a random
   three-letter word. This random word comes from a list of ten three-letters words. If the user
   enters the correct word in less than two seconds, success message is prited, otherwise failed.
   Ignore character case.
*/

#include <windows.h>

#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <string>

std::string words[10] = {"CAT", "RAT", "BAT", "CAP", "BAG", "RAG", "RAP", "BET", "BEG", "LET"};

int main() {
    std::mt19937 gen(42);  // Fixed seed for repeatability
    std::uniform_int_distribution<> r_word(0, 9);
    std::uniform_int_distribution<> r_time(4, 10);

    bool finished = false;
    std::string input, word;

    std::cout << "Prepare for the game... Go!" << std::endl;
    do {
        Sleep(1000 * r_time(gen));
        auto start = std::chrono::high_resolution_clock::now();
        word = words[r_word(gen)];
        std::cout << "Type the word '" << word << "': " << std::flush;
        std::cin >> input;
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_time = end - start;
        std::transform(input.begin(), input.end(), input.begin(), toupper);
        if ((input == word) && (elapsed_time.count() <= 2.0)) {
            finished = true;
            std::cout << "Congratulations, you typed the right word in " << elapsed_time.count()
                      << " seconds." << std::endl;
        } else if ((input == word) && (elapsed_time.count() > 2.0)) {
            std::cout << "This was close, you typed the right word but in " << elapsed_time.count()
                      << " seconds. Try again!" << std::endl;
        } else {
            std::cout << "Wrong word, try again!" << std::endl;
        }
    } while (!finished);

    return 0;
}