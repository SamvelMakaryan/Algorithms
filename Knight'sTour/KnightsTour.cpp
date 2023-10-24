#include <iostream>
#include <iomanip>
#include <vector>
#include <array>

#include "Solver.hpp"

int main() {
    int n;
    int start_x;
    int start_y;
    do {
        std::cout << "Enter the size of the chessboard between the range [4, 16]: ";
        std::cin >> n;
    } while (n < 4 || n > 16);
    do {
        std::cout << "Enter the starting position (x) within the board size (0 to " << n - 1 << "): ";
        std::cin >> start_x;
        std::cout << "Enter the starting position (y) within the board size (0 to " << n - 1 << "): ";
        std::cin >> start_y;
    } while (start_x < 0 || start_x >= n || start_y < 0 || start_y >= n);
    std::vector<std::vector<int>> board(n, std::vector<int>(n, -1));
    board[start_x][start_y] = 0;
    if (solveKnightTour(start_x, start_y, 1, board, n)) {
        std::cout << "Knight's Tour Solution:\n";
        printBoard(board, n);
    } else {
        std::cout << "No board found." << std::endl;
    }
}

