#include <iostream>
#include <vector>

void printBoard(std::vector<std::vector<bool>>& board) {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            std::cout << (board[i][j] ? "♕" : ".") << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool isSafe(std::vector<std::vector<bool>>& board, int row, int col, int N, int M) {
    for (int i = 0; i < row; ++i) {
        if (board[i][col])
            return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j])
            return false;
    }
    for (int i = row, j = col; i >= 0 && j < M; --i, ++j) {
        if (board[i][j])
            return false;
    }
    return true;
}

int solveNQueens(std::vector<std::vector<bool>>& board, int row, int N, int M) {
    if (row == N) {
        printBoard(board);
        return 1;
    }
    int totalSolutions = 0;
    for (int col = 0; col < M; ++col) {
        if (isSafe(board, row, col, N, M)) {
            board[row][col] = true;
            totalSolutions += solveNQueens(board, row + 1, N, M);
            board[row][col] = false;
        }
    }
    return totalSolutions;
}
