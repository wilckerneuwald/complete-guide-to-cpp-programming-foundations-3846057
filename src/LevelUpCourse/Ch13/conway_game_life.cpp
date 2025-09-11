/*
    10x10 grid wrapping around in all directions.
    Every cell has 8 neighbors.
    Any cell with < 2 neighbors dies.
    Any cell with two or three living neighbors lives on to the next generation.
    Any cell with more than 3 living neighbors dies.
    Any dead cell with exactly three living neighbors becomes a live cell as if by reproduction.

    Test two initial conditions: blinker and glider. Test also R-pentomino.
*/

#include <windows.h>

#include <array>
#include <iostream>
#include <string>

#define BOARD_SIZE 10
using board_t = std::array<std::array<int, BOARD_SIZE>, BOARD_SIZE>;

void print(const board_t& board) {
    std::string line;
    for (int i = 0; i < BOARD_SIZE; i++) {
        line = "";
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j])
                line += " # ";
            else
                line += " . ";
        }
        std::cout << line << std::endl;
    }
    std::cout << std::endl;
}

void init_blinker(board_t& board) {
    // int mid = BOARD_SIZE / 2;
    // for (int i = mid - 1; i <= mid + 1; i++) {
    //     board[i][mid] = 1;
    // }

    // A blinker      // - - - - - - - - - -
    board[3][6] = 1;  // - - - - - - - - - -
    board[3][7] = 1;  // - - - - - - - - - -
    board[3][8] = 1;  // - - - - - - X X X -
}

void init_glider(board_t& board) {
    // int i;
    // int mid = BOARD_SIZE / 2;
    // for (i = mid - 1; i <= mid + 1; i++) {
    //     board[i][mid] = 1;
    // }
    // board[i - 1][mid - 1] = 1;
    // board[i - 2][mid - 2] = 1;

    // A glider       // - - - - - - - - - -
    board[1][1] = 1;  // - X - - - - - - - -
    board[2][2] = 1;  // - - X - - - - - - -
    board[3][0] = 1;  // X X X - - - - - - -
    board[3][1] = 1;
    board[3][2] = 1;
}

void init_r_pentomino(board_t& board) {
    int i;
    int mid = BOARD_SIZE / 2;
    for (i = mid - 1; i <= mid + 1; i++) {
        board[i][mid] = 1;
    }
    board[i - 2][mid - 1] = 1;
    board[i - 3][mid + 1] = 1;
}

int count_neighbors(const board_t& board, int row, int col) {
    int neighbors = 0;
    int row_plus = (row + 1 == BOARD_SIZE) ? 0 : row + 1;
    int row_minus = (row - 1 < 0) ? BOARD_SIZE - 1 : row - 1;
    int col_plus = (col + 1 == BOARD_SIZE) ? 0 : col + 1;
    int col_minus = (col - 1 < 0) ? BOARD_SIZE - 1 : col - 1;
    neighbors += board[row][col_minus];
    neighbors += board[row][col_plus];
    neighbors += board[row_plus][col];
    neighbors += board[row_plus][col_plus];
    neighbors += board[row_plus][col_minus];
    neighbors += board[row_minus][col];
    neighbors += board[row_minus][col_plus];
    neighbors += board[row_minus][col_minus];
    return neighbors;
}

void update(board_t& board) {
    board_t neighbors = {};
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            neighbors[i][j] = count_neighbors(board, i, j);
        }
    }
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            // Update dead cells
            if (neighbors[i][j] < 2) board[i][j] = 0;
            if (neighbors[i][j] > 3) board[i][j] = 0;
            // Update born cells
            if (neighbors[i][j] == 3) board[i][j] = 1;
        }
    }
}

int main() {
    board_t board = {};
    init_blinker(board);
    init_glider(board);
    // init_r_pentomino(board);  // change board size to 25

    int generations = 30;
    for (int i = 0; i < generations; i++) {
        std::cout << "Generation: " << i + 1 << std::endl;
        print(board);
        update(board);
        Sleep(500);
    }
    return 0;
}