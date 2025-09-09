/*
    Return all possible moves for a chess knight given its initial position [file, rank].
*/

#include <iostream>
#include <set>
#include <utility>

using pos = std::pair<char, int>;
using mov = std::pair<int, int>;

bool is_valid_position(const pos& position) {
    bool verdict = true;
    if (position.first < 'a' || position.first > 'h') verdict = false;
    if (position.second < 1 || position.second > 8) verdict = false;
    return verdict;
}

bool is_valid_move(const mov& move) {
    return move.first * move.first + move.second * move.second == 5;
}

std::set<pos> get_horse_plays(const pos& position) {
    std::set<pos> plays;
    const std::set<int> increments = {1, 2, -1, -2};
    for (int i : increments) {
        for (int j : increments) {
            if (is_valid_move(mov{i, j})) {
                pos new_pos = pos{static_cast<char>(position.first + i), position.second + j};
                if (is_valid_position(new_pos)) plays.insert(new_pos);
            }
        }
    }
    return plays;
}

int main() {
    pos position = {'d', 5};
    std::set<pos> plays = get_horse_plays(position);
    for (auto play : plays) std::cout << play.first << play.second << std::endl;
    return 0;
}