#include <iostream>
#include <vector>

#include "Helper.hpp"

int main() {
    int N, M;
    std::cout << "Enter the dimensions (N M) of the chessboard: ";
    std::cin >> N >> M;
	if (N <= 0 || M <= 0) {
		std::cerr << "Invalid dimensions" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	if (N > M) {
		std::swap(N, M);
	}
    std::vector<std::vector<bool>> board(N, std::vector<bool>(M, 0));
    int numSolutions = solveNQueens(board, 0, N, M);
    if (numSolutions == 0) {
        std::cout << "No solutions found." << std::endl;
    } else {
        std::cout << "Total solutions found: " << numSolutions << std::endl;
    }
}

