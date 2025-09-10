/*
    Read peoples names in a csv file and display message with first pair of people who might be
   related. All entries have one name and one surname, separated by spaces.
*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using pstring = std::pair<std::string, std::string>;
using vec_pstring = std::vector<pstring>;

int main() {
    std::ifstream file("names.csv");
    std::string line;
    std::string cell;
    pstring full_name;
    vec_pstring all_names;
    bool relatives_found = false;

    while (std::getline(file, line)) {
        std::stringstream ss(line);

        while (std::getline(ss, cell, ',')) {
            auto space = std::find(cell.begin(), cell.end(), ' ');
            size_t index = std::distance(cell.begin(), space);
            full_name.first = cell.substr(0, index);
            full_name.second = cell.substr(index + 1, cell.size());
            for (pstring name : all_names) {
                if (name.second == full_name.second) {
                    std::cout << "First pair of relatives are: " << name.first << " " << name.second
                              << " and " << full_name.first << " " << full_name.second << std::endl;
                    relatives_found = true;
                    break;
                }
            }
            all_names.push_back(full_name);
            if (relatives_found) break;
        }
        if (relatives_found) break;
    }

    return 0;
}