/*
    Write artificially intelligent game that plays tic-tac-toe.
    Give user the chance to make a move.
    Then AI makes a move.
*/

#include <iostream>
#include <random>
#include <set>
#include <string>
#include <utility>

using pos = std::pair<int, int>;

void display_table(const std::set<pos>& user_played_positions,
                   const std::set<pos>& bot_played_positions) {
    std::string line;
    for (int i = 1; i <= 3; i++) {
        line = "_|_|_";
        for (pos user : user_played_positions)
            if (user.first == i)
                line[(user.second - 1) * 2] = 'x';  // Substitute '_' for 'x' for the user
        for (pos bot : bot_played_positions)
            if (bot.first == i)
                line[(bot.second - 1) * 2] = 'o';  // Substitute '_' for 'o' for the bot

        std::cout << line << std::endl;
    }
}

bool is_valid_arg(const std::string& arg) { return (arg == "1") || (arg == "2") || (arg == "3"); }

bool is_valid_position(const pos& new_pos, const std::set<pos>& user_played_positions,
                       const std::set<pos>& bot_played_positions) {
    for (pos position : user_played_positions) {
        if (new_pos == position) return false;  // Position already played by user
    }
    for (pos position : bot_played_positions) {
        if (new_pos == position) return false;  // Position already played by bot
    }
    return true;
}

void bot_plays(const std::set<pos>& user_played_positions, std::set<pos>& bot_played_positions,
               std::mt19937 gen) {
    std::uniform_int_distribution<> dist(1, 3);
    bool valid_play = false;
    pos bot_play(0, 0);
    do {
        bot_play.first = dist(gen);
        bot_play.second = dist(gen);
        valid_play = is_valid_position(bot_play, user_played_positions, bot_played_positions);
        if (valid_play) bot_played_positions.insert(bot_play);
    } while (!valid_play);
}

bool is_game_won(const std::set<pos>& played_positions) {
    int lines_sum[3] = {0, 0, 0};
    int columns_sum[3] = {0, 0, 0};
    int main_diag_sum = 0;
    int sec_diag_sum = 0;
    bool game_won = false;

    for (int i = 1; i <= 3; i++) {
        for (pos play : played_positions) {
            if (i == play.first) lines_sum[i - 1]++;
            if (i == play.second) columns_sum[i - 1]++;
            if (i == play.first && i == play.second) main_diag_sum++;
            if (((4 - i) == play.first) && (i == play.second)) sec_diag_sum++;
        }
    }

    for (int i = 0; i < 3; i++) {
        game_won |= lines_sum[i] == 3;
        game_won |= columns_sum[i] == 3;
    }
    game_won |= main_diag_sum == 3;
    game_won |= sec_diag_sum == 3;

    return game_won;
}

bool is_game_finished(const std::set<pos>& user_played_positions,
                      const std::set<pos>& bot_played_positions) {
    // Check if user won the game
    if (is_game_won(user_played_positions)) {
        std::cout << "Contratulations. You won!" << std::endl;
        return true;
    }
    // Check if bot won the game
    if (is_game_won(bot_played_positions)) {
        std::cout << "I'm sorry. You lost!" << std::endl;
        return true;
    }
    if (user_played_positions.size() == 5) {
        std::cout << "Game is over. This time it was a draw! Try again..." << std::endl;
        return true;  // Game finished when user played 5 times and no winner was found.
    }
    return false;
}

int main() {
    std::mt19937 gen(42);  // Fixed seed for repeatability of bot behavior

    bool game_finished = false;
    std::string line, column;
    std::set<pos> user_played_positions;
    std::set<pos> bot_played_positions;
    while (!game_finished) {
        std::cout << "Check out the current table position where you are represented by 'x' and "
                     "the bot by 'o'."
                  << std::endl;
        display_table(user_played_positions, bot_played_positions);
        std::cout << "Enter line {1, 2 or 3} or 'q' to exit: " << std::flush;
        std::cin >> line;
        if (line == "q") break;
        if (!is_valid_arg(line)) {
            std::cout << "Invalid line inserted. Try again..." << std::endl;
            continue;
        }
        std::cout << "Enter column {1, 2 or 3}  or 'q' to exit: " << std::flush;
        std::cin >> column;
        if (column == "q") break;
        if (!is_valid_arg(column)) {
            std::cout << "Invalid column inserted. Try again..." << std::endl;
            continue;
        }
        pos new_position = pos(std::stoi(line), std::stoi(column));
        if (is_valid_position(new_position, user_played_positions, bot_played_positions)) {
            user_played_positions.insert(new_position);
        } else {
            std::cout << "Position was already played. Try again..." << std::endl;
            continue;
        }
        game_finished = is_game_finished(user_played_positions, bot_played_positions);
        if (game_finished) break;
        bot_plays(user_played_positions, bot_played_positions, gen);
        game_finished = is_game_finished(user_played_positions, bot_played_positions);
    }

    std::cout << "Final Position:" << std::endl;
    display_table(user_played_positions, bot_played_positions);

    return 0;
}