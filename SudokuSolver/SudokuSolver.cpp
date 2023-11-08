#include "SudokuSolver.hpp"

bool isSafe(const std::vector<std::vector<int>>& board, int row, int col, int num) {
    for (int i = 0; i < boardSize; ++i) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }
    int currentRow = row - row % cubeSize;
    int currentCol = col - col % cubeSize;
    for (int i = 0; i < cubeSize; ++i) {
        for (int j = 0; j < cubeSize; ++j) {
            if (board[currentRow + i][currentCol + j] == num) {
                return false;
            }
        }
    }
    return true;
}

bool sudokuSolverHelper(std::vector<std::vector<int>>& board, int row, int col) {
    if (row == boardSize - 1 && col == boardSize) {
        return true;
    }
    if (col == boardSize) {
        ++row;
        col = 0;
    }
    if (board[row][col]) {
        return sudokuSolverHelper(board, row, col + 1);
    }
    for (int i = 1; i <= boardSize; ++i) {
        if (isSafe(board, row, col, i)) {
            board[row][col] = i;
            if (sudokuSolverHelper(board, row, col + 1)) {
                return true;
            }
        }
        board[row][col] = 0;
    }
    return false;
}

bool sudokuSolver(std::vector<std::vector<int>>& board) {
    return sudokuSolverHelper(board, 0, 0);
}

void printBoard(const std::vector<std::vector<int>>& board) {
    std::cout << std::endl;
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            std::cout << board[i][j] << " ";
            if ((j + 1) % cubeSize == 0) {
                std::cout << " ";
            }
        }
        if ((i + 1) % cubeSize == 0) {
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}