/*
    Calculate age in days based on birthday date.
    Common years: 365 days
    Leap years: 366 days
    If not divisible by 4 -> common
        if not divisible by 100 -> leap
            if not divisible by 400 -> common
            else -> leap
*/

#include <ctime>
#include <deque>
#include <exception>
#include <iostream>
#include <sstream>
#include <string>

const unsigned char month_length[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leap_year(int year) {
    if (year % 4) return false;
    if (year % 100) return true;
    if (year % 400) return false;
    return true;
}

int get_if_valid_byte(const std::string& byte, const int& max_value) {
    int int_byte;
    try {
        int_byte = std::stoi(byte);
        if (int_byte < 0 || int_byte > max_value) int_byte = 0;
    } catch (std::exception e) {
        std::cout << "Exception raised: " << e.what() << std::endl;
        int_byte = 0;
    }
    return int_byte;
}

int is_valid_date(const std::string& date, std::deque<int>& output_date, const int& current_year,
                  const int& current_month, const int& current_day) {
    int intbyte;
    int result = 1;
    int count_bytes = 0;
    std::string byte;
    std::string reverse_date = std::string(date.rbegin(), date.rend());
    std::stringstream ss(reverse_date);
    const char delimiter = '.';

    while (getline(ss, byte, delimiter)) {
        count_bytes++;
        byte = std::string(byte.rbegin(), byte.rend());  // Reverse byte back to normal
        switch (count_bytes) {
            case 1:
                intbyte = get_if_valid_byte(byte, current_year);
                output_date.push_front(intbyte);
                result = result && intbyte;
                break;
            case 2:
                intbyte =
                    get_if_valid_byte(byte, current_year == output_date[0] ? current_month : 12);
                output_date.push_front(intbyte);
                result = result && intbyte;
                break;
            case 3:
                int max_value;
                if ((current_year == output_date[1]) && (current_month == output_date[0])) {
                    max_value = current_day;
                } else if ((output_date[0] == 2) && is_leap_year(output_date[1])) {
                    max_value = 29;
                } else {
                    max_value = month_length[output_date[0] - 1];
                }
                intbyte = get_if_valid_byte(byte, max_value);
                output_date.push_front(intbyte);
                result = result && intbyte;
                break;
            default:
                result = 0;
        }
    }

    return result;
}

int count_age(const int& today_y, const int& today_m, const int& today_d, const int& bd_y,
              const int& bd_m, const int& bd_d) {
    int age = 0;
    for (int y = bd_y; y < today_y; y++) {
        age += is_leap_year(y) ? 366 : 365;
    }
    for (int m = bd_m; m < today_m; m++) {
        age += month_length[m - 1];
        if (is_leap_year(today_y) && m == 2) age++;
    }
    for (int d = bd_d; d < today_d; d++) {
        age++;
    }
    return age;
}

int main() {
    time_t now = std::time(0);
    struct tm tstruct;
    tstruct = *localtime(&now);
    int today_d = tstruct.tm_mday;
    int today_m = tstruct.tm_mon + 1;
    int today_y = tstruct.tm_year + 1900;

    std::cout << "Today is: " << today_d << "." << today_m << "." << today_y << std::endl;

    std::string birthday;
    std::deque<int> parsed_date;
    while (true) {
        std::cout << "Enter your birthday date in format 'dd.mm.yyyy'. Type 'q' to exit: "
                  << std::flush;
        std::cin >> birthday;

        if (birthday == "q") break;

        if (is_valid_date(birthday, parsed_date, today_y, today_m, today_d)) {
            int bd_d = parsed_date[0];
            int bd_m = parsed_date[1];
            int bd_y = parsed_date[2];
            int age = count_age(today_y, today_m, today_d, bd_y, bd_m, bd_d);
            if (age < 43830)  // Approx. 120 years
                std::cout << "You are " << age << " days old." << std::endl;
            else
                std::cout << "Come on. You can't be " << age << " days old!" << std::endl;
        } else {
            std::cout << "Invalid birthday date!" << std::endl;
        }
    }

    return 0;
}