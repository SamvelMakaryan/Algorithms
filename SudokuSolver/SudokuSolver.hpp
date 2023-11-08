#ifndef SUDOKUSOLVER_HPP_
#define SUDOKUSOLVER_HPP_

#include <iostream>
#include <vector>

bool sudokuSolver(std::vector<std::vector<int>>&);
bool sudokuSolverHelper(std::vector<std::vector<int>>&, int, int);
bool isSafe(const std::vector<std::vector<int>>&, int, int, int);
void printBoard(const std::vector<std::vector<int>>&);  

constexpr int boardSize = 9;
constexpr int cubeSize = 3;

#endif //SUDOKUSOLVER_HPP_