#ifndef HELPER_HPP_
#define HELPER_HPP_

#include <iostream>
#include <vector>

void printBoard(std::vector<std::vector<bool>>&);
bool isSafe(std::vector<std::vector<bool>>& board, int row, int col, int N, int M);
int solveNQueens(std::vector<std::vector<bool>>& board, int row, int N, int M);

#endif //HELPER_HPP_
