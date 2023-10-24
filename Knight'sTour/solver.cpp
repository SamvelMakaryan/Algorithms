#include <iostream>
#include <iomanip>
#include <vector>
#include <array>

bool isSafe(int x, int y, int n, std::vector<std::vector<int>>& board) {
    return (x >= 0 && y >= 0 && x < n && y < n && board[x][y] == -1);
}

void printBoard(const std::vector<std::vector<int>>& board, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << std::setw(3) << std::left << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool solveKnightTour(int x, int y, int moveCount, std::vector<std::vector<int>>& board, int n) {
    constexpr std::array<int, 8> move_x = {2, 1, -1, -2, -2, -1, 1, 2};
    constexpr std::array<int, 8> move_y = {1, 2, 2, 1, -1, -2, -2, -1};
    if (moveCount == n * n) {
        return true;
    }
    for (int i = 0; i < 8; ++i) {
        int next_x = x + move_x[i];
        int next_y = y + move_y[i];
        if (isSafe(next_x, next_y, n, board)) {
            board[next_x][next_y] = moveCount;
            if (solveKnightTour(next_x, next_y, moveCount + 1, board, n)) {
                return true;
            } else {
                board[next_x][next_y] = -1;
            }
        }
    }
    return false;
}