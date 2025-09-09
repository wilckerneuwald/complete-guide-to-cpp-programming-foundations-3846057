/*
    Reads a string from terminal and check if it is a valid IPv4 address or not.
    Decimal IP addresses, 32 bits, between 0 and 255.
*/

#include <exception>
#include <iostream>
#include <sstream>
#include <string>

bool is_valid_byte(const std::string& byte) {
    bool result = true;
    try {
        int int_byte = std::stoi(byte);
        if (int_byte < 0 || int_byte > 255) result = false;
    } catch (std::exception e) {
        std::cout << "Exception raised: " << e.what() << std::endl;
        result = false;
    }
    return result;
}

bool is_valid_ip(const std::string& ip) {
    bool result = true;
    const char delimiter = '.';
    std::string byte;
    std::stringstream ss(ip);
    int count_bytes = 0;

    while (getline(ss, byte, delimiter)) {
        count_bytes++;
        result &= is_valid_byte(byte);
    }

    result &= count_bytes == 4;

    return result;
}

int main() {
    std::string ip;

    while (true) {
        std::cout << "Enter a decimal IPv4 Address. Type 'q' to exit: " << std::flush;
        std::cin >> ip;

        if (ip == "q") break;

        bool result = is_valid_ip(ip);

        if (result)
            std::cout << "Valid IPv4 Address!" << std::endl;
        else
            std::cout << "Invalid IPv4 Address!" << std::endl;
    }

    return 0;
}