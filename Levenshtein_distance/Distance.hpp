#ifndef DISTANCE_HPP_
#define DISTANCE_HPP_
#include <algorithm>
#include <vector>
#include <string>

int distance(const std::string& word1, const std::string& word2) {
	int n1 = word1.size();
	int n2 = word2.size();
	std::vector<std::vector<int>> mat(n1 + 1, std::vector<int>(n2 + 1, 0));
	for (int i = 0; i <= n1; ++i) {
		mat[i][0] = i;
	}
	for (int i = 0; i <= n2; ++i) {
		mat[0][i] = i;
	}
	for (int i = 1; i <= n1; ++i) {
		for (int j = 1; j <= n2; ++j) {
			if (word1[i - 1] == word2[j - 1]) {
				mat[i][j] = mat[i - 1][j - 1];
			}
			else {
				mat[i][j] = 1 + std::min({mat[i - 1][j], mat[i][j - 1], mat[i - 1][j - 1]});
			}
		}
	}
	return mat[n1][n2];
}

//Time complexity O(m * n)
//Space complexity O(m * n)
//where m is sie of word1 and n is size of word2 

#endif //DISTANCE_HPP_
