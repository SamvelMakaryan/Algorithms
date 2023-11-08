#include <iostream>
#include <vector>

#include "SudokuSolver.hpp"

int main() {
    std::vector<std::vector<int>> board(boardSize, std::vector<int>(boardSize, 0));
    if (sudokuSolver(board)) {
        std::cout << "The solution is" << std::endl;
        printBoard(board);
    } else {
        std::cout << "No solution exists" << std::endl;
    }
}
